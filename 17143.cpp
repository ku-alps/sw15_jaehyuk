#include<bits/stdc++.h>
using namespace std;
int R,C,M;
int dir[4][2] ={{-1,0},{1,0},{0,1},{0,-1}}; //위,아래,오른쪽,왼쪽
struct shark{
    int r,c,s,d,z;
};
vector<shark> arr;
pair<int,int> board[101][101];  //{상어번호, 크기}
//O(C*M)
int ans = 0;
void doing(int col){
    int _min = 100000;
    int idx =-1;
    for(int i= 0; i<M; i++){
        if(arr[i].c == col && arr[i].z != -1){
            if(_min>arr[i].r){
                idx = i;
                _min = arr[i].r;
            }
        }
    }
    if(idx != -1){
        ans+= arr[idx].z;
        arr[idx].z = -1;
    }
}
void move(){
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            board[i][j] = make_pair(0,0);
        }
    }
    for(int i = 0; i<M; i++){
        if(arr[i].z != -1){
            int r = arr[i].r;
            int c = arr[i].c;
            int d = arr[i].d;
            int s = arr[i].s;
            
            if(d<=1){
            if((s/(R-1))%2==1)
            {s=s%(R-1)+R-1;}
            else
            {s=s%(R-1);}
            }
            else
            {
            if((s/(C-1))%2==1)
            {s=s%(C-1)+C-1;}
            else
            {s=s%(C-1);}
            
            }
            while(s>0){
                r += dir[d][0];
                c += dir[d][1];
                s--;
                if(r<0 || r>R-1 || c<0 || c>C-1){
                    r -= dir[d][0];
                    c -= dir[d][1];
                    if(d == 0){
                        d = 1;
                    }
                    else if(d == 1){
                        d = 0;
                    }
                    else if(d == 2){
                        d = 3;
                    }
                    else{
                        d = 2;
                    }
                    s++;
                }   
            }
            arr[i].r = r;
            arr[i].c = c;
            arr[i].d = d;
            if(board[r][c].second==0){
                board[r][c].first = i;
                board[r][c].second = arr[i].z;
            }
            else{
                if(board[r][c].second > arr[i].z){
                    arr[i].z = -1;
                } 
                else{
                    board[r][c].second = arr[i].z;
                    arr[board[r][c].first].z = -1;
                    board[r][c].first = i;
                }
            }
        }
    }
}
int main(){
    cin>>R>>C>>M;    
    arr.resize(M);
    int input_d,input_r,input_c;
    for(int i= 0; i<M; i++){
        cin>>input_r>>input_c>>arr[i].s;
        cin>>input_d;
        arr[i].r = input_r-1;
        arr[i].c = input_c-1;
        arr[i].d = input_d-1;
        cin>>arr[i].z;
    }
    for(int i = 0; i<C; i++){
        doing(i);
        move();
    }
    cout<<ans<<endl;
}