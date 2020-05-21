#include<bits/stdc++.h>
using namespace std;
int N,M;
int board[10][10];
int temp[10][10];
vector<pair<int,int> > virus;
void mycopy(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            temp[i][j] = board[i][j];
        }
    }
}
int mmax = 0;
int main(){
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
        }
    }

    for(int a = 0; a<N; a++){
        for(int b = 0; b<M; b++){
            if(board[a][b] != 0){
                continue;
            }
            for(int c = 0; c<N; c++){
                for(int d = 0; d<M; d++){
                    if(board[c][d] != 0){
                        continue;
                    }
                    if(a == c &&b==d){
                        continue;
                    }
                    for(int e = 0; e<N; e++){
                        for(int f = 0; f<M; f++){
                            if(board[e][f] != 0){
                                continue;
                            }
                            if(a == e && b == f)
                            {   continue; }
                            if(c == e && d == f)
                            {   continue; }
                            mycopy();
                            temp[a][b] = 1;
                            temp[c][d] = 1;
                            temp[e][f] = 1;

                            queue<pair<int, int> > que;
                            int visited[10][10] = {0};
                            
                            for(int i = 0; i<N; i++){
                                for(int j = 0; j<M; j++){
                                    if(temp[i][j] != 2){
                                        continue;
                                    }
                                    que.push(make_pair(i,j));
                                    while(!que.empty()){
                                        pair<int,int> idx = que.front();
                                        que.pop();
                                        if(visited[idx.first][idx.second] == 1){
                                            continue;
                                        }
                                        visited[idx.first][idx.second] = 1;
                                        if(idx.first-1>=0 && temp[idx.first-1][idx.second] == 0){
                                            temp[idx.first-1][idx.second] = 2;
                                            que.push(make_pair(idx.first-1,idx.second));
                                        }
                                        if(idx.second-1>=0 && temp[idx.first][idx.second-1] == 0){
                                            temp[idx.first][idx.second-1] = 2;
                                            que.push(make_pair(idx.first,idx.second-1));
                                        }
                                        if(idx.first+1<=N-1 && temp[idx.first+1][idx.second] == 0){
                                            temp[idx.first+1][idx.second] = 2;
                                            que.push(make_pair(idx.first+1,idx.second));
                                        }
                                        if(idx.second+1<=M-1 && temp[idx.first][idx.second+1] == 0){
                                            temp[idx.first][idx.second+1] = 2;
                                            que.push(make_pair(idx.first,idx.second+1));
                                        }
                                    }
                                }
                            }
                            
                            int sum = 0;
                            for(int i = 0; i<N; i++){
                                for(int j = 0; j<M; j++){
                                    if(temp[i][j] == 0){
                                        sum++;
                                    }
                                }
                            }
                            mmax = max(mmax,sum);
                        }
                    }
                }
            }
        }
    }
    cout<<mmax<<endl;
}