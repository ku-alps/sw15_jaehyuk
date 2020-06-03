
//DFS
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > board;
vector<vector<int> > visited;
int N,L,R;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int cnt = 0;
//int ans = 0;
int dfs(int r,int c){
    int sum = board[r][c];
    if(visited[r][c] >= 1)return 0;
    visited[r][c] = 1;
    cnt++;
    for(int i= 0; i<4; i++){
        int x = r+dir[i][0];
        int y = c+dir[i][1];
        if(x<0 || y<0 || x>N-1 || y>N-1) continue;
        if((abs(board[x][y] - board[r][c])>=L) && (abs(board[x][y] - board[r][c])<=R))
            sum+=dfs(x,y);
    }
    return sum;
}
int isMove(int x,int y){  
    int sum = dfs(x,y);
    if(cnt == 0){
        return 0;
    }
    int res = sum/cnt;
    if(cnt == 1){
        cnt = 0;
        visited[x][y] = 2;
        return 0;
    }
    //ans++;
    for(int i= 0 ;i<N; i++){
        for(int j = 0; j<N; j++){
            if(visited[i][j] == 1){
                board[i][j] = res;
                visited[i][j] = 2;
            }
        }
    }
    cnt = 0;
    return 1;
}
int main(){
    cin>>N>>L>>R;
    board.resize(N,vector<int>(N));
    visited.resize(N,vector<int>(N));
    for(int i= 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
        }
    }
    int ans = 0;
    while(true){
        int lcnt = 0;
        auto bak = visited;
        for(int x = 0; x<N; x++){
            for(int y = 0; y<N; y++){
                lcnt+=isMove(x,y);
            }
        }
        visited = bak;
        if(lcnt == 0){
            break;
        }
        ans++;
    }
    cout<<ans<<endl;
}