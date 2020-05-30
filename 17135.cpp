#include<bits/stdc++.h>
#include<limits>
using namespace std;
int N,M,D;
int board[16][16] = {0};
int temp[16][16] = {0};
int kills=0;
pair<int,int> shoot(int num){
    int r = N;
    int c = num;
    int _min = INT_MAX;
    int mr=-1,mc=-1;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if((board[i][j] == 1)&&((abs(r-i)+abs(c-j))<=D)){
                if(_min>(abs(r-i)+abs(c-j))){
                    mr = i;
                    mc = j;
                    _min = abs(r-i)+abs(c-j);
                }
                else if(_min == abs(r-i)+abs(c-j)){
                    if(mc > j){
                        mr = i;
                        mc = j;
                    }
                }
            }
        }
    }
    return make_pair(mr,mc);
}
int main(){
    cin>>N>>M>>D;
    int max_kill = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0 ; j<M; j++){
            cin>>board[i][j];
            temp[i][j] = board[i][j];
        }
    }
    for(int i = 0; i<=M; i++){
        for(int j = 0; j<=M; j++){
            if(i == j)continue;
            for(int k = 0; k<=M; k++){
                if(i==k || j==k)continue;
                kills = 0;
                
                for(int x = 0; x<N; x++){
                    for(int y = 0; y<M; y++){
                        board[x][y] = temp[x][y];
                    }
                }
                while(true){
                    
                    pair<int,int> a = shoot(i);
                    pair<int,int> b = shoot(j);
                    pair<int,int> c = shoot(k);
                    if(a.first != -1 && a.second != -1){
                        if(board[a.first][a.second] == 1){
                            kills++;
                            board[a.first][a.second] = 0;
                        }
                    }
                    if(b.first != -1 && b.second != -1){
                        if(board[b.first][b.second] == 1){
                            kills++;
                            board[b.first][b.second] = 0;
                        }
                    }
                    if(c.first != -1 && c.second != -1){
                        if(board[c.first][c.second] == 1){
                            kills++;
                            board[c.first][c.second] = 0;
                        }
                    }

                    for(int x = N-2; x>=0; x--){
                        for(int y = 0; y<M; y++){
                            board[x+1][y] = board[x][y];
                        }
                    }
                    for(int x = 0; x<M; x++){
                        board[0][x] = 0;
                    }
                    int sum = 0;
                    for(int x = 0; x<N; x++){
                        for(int y = 0; y<M; y++){
                            sum+= board[x][y];
                        }
                    }
                    if(sum == 0){
                        break;
                    }            
                }
                
                max_kill = max(max_kill,kills);
            }
        }
    }
    cout<<max_kill;
}