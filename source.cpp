/**/
// 15683 감시
#include<bits/stdc++.h>
#include<limits>
using namespace std;
int N,M;
int board[8][8];
int cboard[8][8];
int dir[4][2] ={{1,0},{0,1},{-1,0},{0,-1}};
struct cctv{
    int x,y,s;
};
struct status{
    vector<int> cases;
};
vector<cctv> vec;
void _init(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            board[i][j] = cboard[i][j];
        }
    }
}
void _print(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
void doing(int idx,int d){
    int r = vec[idx].x;
    int c = vec[idx].y;
    while(true){
        r += dir[d][0];
        c += dir[d][1];
        if(r<0 || r>N-1 || c<0 ||c>M-1){
            break;
        }
        if(board[r][c] == 6){
            break;
        }
        if(board[r][c] == 0){
            board[r][c] = 7;
        }
    }
}
int move(status s){
    for(int i = 0; i<s.cases.size(); i++){
        //cout<<s.cases[i]<<" ";
        int k = s.cases[i];
        switch(vec[i].s){
            case 1:{
                doing(i,k);
                break;
            }
            case 2:{
                doing(i,k);
                doing(i,(k+2)%4);
                break;
            }
            case 3:{
                doing(i,k);
                doing(i,(k+1)%4);
                break;
            }
            case 4:{
                doing(i,k);
                doing(i,(k+1)%4);
                doing(i,(k+2)%4);
                break;
            }
            case 5:{
                doing(i,0);
                doing(i,1);
                doing(i,2);
                doing(i,3);
                break;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] == 0){
                sum++;
            }
        }
    }
    // _print();
    // cout<<endl;
    _init();
    return sum;
};
int dfs(status s){
    int _min = INT_MAX;
    if(vec.size()>0&&(s.cases.size()<vec.size())){
        for(int i= 0; i<4; i++){
            status temp;
            for(int i = 0; i<s.cases.size(); i++){
                temp.cases.push_back(s.cases[i]);
            }
            temp.cases.push_back(i);
            _min = min(_min,dfs(temp));
        }
    }
    else{
        return move(s);
    }
    return _min;
}
int main(){
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
            cboard[i][j] = board[i][j];
            if(board[i][j]>0 &&board[i][j]<6){
                cctv temp = {i,j,board[i][j]};
                vec.push_back(temp);
            }
        }
    }
    int _min = INT_MAX;
    int sum = 0;
    if(vec.size()>0){
        for(int i = 0; i<4; i++){
            status start;
            start.cases.push_back(i);
            _min = min(_min,dfs(start));
        }
        cout<<_min;
        return 0;
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] == 0){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
/**/