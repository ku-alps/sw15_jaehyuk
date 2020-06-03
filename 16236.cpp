#include<bits/stdc++.h>
using namespace std;
int N,S=2,E=0,T=0;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int visited[20][20] = {0};
int r,c;
vector<vector<int> > board;
bool cmp(pair<int, pair<int,int> > &a, pair<int, pair<int,int> > &b){
    if(a.first<b.first){
        return true;
    }
    else if(a.first == b.first){
        if(a.second.first<b.second.first){
            return true;
        }
        else if(a.second.first== b.second.first){
            if(a.second.second<b.second.second){
                return true;
            }
        }
    }
    return false;        
}
int bfs(int a,int b){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            visited[i][j] = 0;
        }
    }
    queue<pair<int, pair<int,int> > > que;
    vector<pair<int,pair<int,int> > > chk;
    que.push(make_pair(0,make_pair(a,b)));

    while(!que.empty()){
        
        pair<int,pair<int,int> > idx = que.front();
        que.pop();
        
        int x = idx.second.first;
        int y = idx.second.second;
        int dist = idx.first;
        
        if(visited[x][y] == 1)
            continue;
        visited[x][y] = 1;

        if(board[x][y] < S && board[x][y] >0){
            chk.push_back(make_pair(dist,make_pair(x,y)));
        }
        for(int i = 0; i<4; i++){
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];

            if((xx<0 || yy<0 || xx>N-1|| yy>N-1)||board[xx][yy] > S){
                continue;
            }
            if(visited[xx][yy] == 0){
                que.push(make_pair(dist+1,make_pair(xx,yy)));
            }
        }
    }
    
    if(chk.size()>0){
        sort(chk.begin(),chk.end(),cmp);
        T += chk.front().first;
        r = chk.front().second.first;
        c = chk.front().second.second;
        E++;
        board[r][c] = 0;
        if(S == E){
            S++,E = 0;
        }
        return 1;
    }
    return 0;
}
int main(){
    cin>>N;
    board.resize(N,vector<int>(N));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
            if(board[i][j] == 9){
                r = i,c = j;
                board[i][j] = 0;
            }
        }
    }
    while(true){
        if(bfs(r,c)==0){
            cout<<T;
            return 0;
        }
    }
}