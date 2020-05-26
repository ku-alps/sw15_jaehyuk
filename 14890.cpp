#include<bits/stdc++.h>
using namespace std;
int N,L;
int board[101][101];
int rroad[101][101] = {0};
int croad[101][101] = {0};
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool chk(int &i, int &j,int d){
    int k = 0;
    if(j+dir[d][1]>N-1 || i+dir[d][0]>N-1 || i+dir[d][0]< 0 || j+dir[d][1]<0)
        return true;
    
    if(board[i][j]<board[i+dir[d][0]][j+dir[d][1]]){
        if(d == 0 || d == 2){
            if(rroad[i][j] == 1 && rroad[i+dir[d][0]][j+dir[d][1]]==1){
                return true;
            }
        }
        else{
            if(croad[i][j] == 1 && croad[i+dir[d][0]][j+dir[d][1]]==1){
                return true;
            }
        }
        return false;
    }
    else if(board[i][j] == board[i+dir[d][0]][j+dir[d][1]]){
        return true;
    }
    else if(board[i][j] > 1+board[i+dir[d][0]][j+dir[d][1]]){
        return false;
    }
    if(d == 0 || d == 2){
        rroad[i][j] = 1;
    }
    else{
        croad[i][j] = 1;
    }
    while(k<L-1){
        i = i+dir[d][0];
        j = j+dir[d][1];
        if(d == 0 || d == 2){
            if(rroad[i][j] == 1){
                return false;
            }
            rroad[i][j] = 1;
        }
        else{
            if(croad[i][j] == 1){
                return false;
            }
            croad[i][j] = 1;
        }
        if(j>N-1 || i>N-1 || i< 0 || j<0){
            return false;
        }
        if(board[i][j] != board[i+dir[d][0]][j+dir[d][1]]){
            return false;
        }
        k++;
    }
    if(d == 0 || d == 2){
        rroad[i][j] = 1;
    }
    else{
        croad[i][j] =1;
    }
    i = i-dir[d][0];
    j = j-dir[d][1];
    
    return true;
}

int main(){
    cin>>N>>L;
    for(int i  = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
        }
    }
    int cnt = 0;
    //가로 루트 N개
    for(int i = 0; i<N; i++){
        bool isOk = true;
        int d;
        for(int j = 0; j<N-1; j++){
            d = 1;
            if(chk(i,j,d)== false){
                isOk = false;
                break;
            }
        }
        if(isOk == true){
            cout<<"1i: "<<i<<endl;
            cnt++;
            continue;
        }
        isOk = true;
        for(int j = N-1; j>0; j--){
            d = 3;
            if(chk(i,j,d)==false){
                isOk = false;
                break;
            }
        }
        if(isOk == true){
            cout<<"2i: "<<i<<endl;
            cnt++;
        }
    }
    //세로 루트 N개
    for(int j = 0; j<N; j++){
        bool isOk = true;
        int d;
        for(int i = 0; i<N-1; i++){
            d = 0;
            if(chk(i,j,d) == false){
                isOk = false;
                break;
            }
        }
        if(isOk == true){
            cnt++;
            cout<<"j: "<<j<<endl;
            continue;
        }
        isOk = true;
        for(int i = N-1; i>0 ;i--){
            d = 2;
            if(chk(i,j,d)==false){
                isOk = false;
                break;
            }
        }
        if(isOk == true){
            cout<<"j: "<<j<<endl;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}