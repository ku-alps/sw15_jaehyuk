#include<bits/stdc++.h>

using namespace std;
priority_queue<pair<int, pair<int,int> > > que;
int M,N;
int maze[100][100];
int visited[100][100] = {0};
int main(){
    cin>>M>>N;
    for(int i = 0; i<N; i++){
        for(int j= 0; j<M; j++){
            cin>>maze[i][j];
        }
    }
    que.push(make_pair(0,make_pair(0,0)));
    while(!que.empty()){
        int dist = que.top().first;
        int x = que.top().second.first;
        int y = que.top().second.second;
        que.pop();
    }
}