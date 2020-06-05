#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct path{
    int r,c,d,b;
};
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int N,M;
int board[1000][1000];
int visited[2][1000][1000];
int main(){
    memset(visited,0,sizeof(visited));
    cin>>N>>M;
    string s;
    for(int i = 0; i<N; i++){
        cin>>s;
        for(int j = 0; j<int(s.length()); j++)
            board[i][j] = s[j]-'0';
    }
    queue<path> que;
    path start = {0,0,1,0};
    que.push(start);
    while(!que.empty()){
        path p = que.front();
        que.pop();
        if(p.r == N-1 && p.c == M-1){
            cout<<p.d;
            return 0;
        }
        if(visited[p.b][p.r][p.c] == 1) continue;
        visited[p.b][p.r][p.c] = 1;
        int x,y;
        for(int i = 0; i<4; i++){
            x = p.r+dir[i][0];
            y = p.c+dir[i][1];
            
            if(x<0 || x>N-1||y<0||y>M-1)
                continue;
            if(p.b == 0){
                if(board[x][y] == 0&&visited[0][x][y] == 0){
                    path n={x,y,p.d+1,0};
                    que.push(n);
                }
                else if(board[x][y] == 1&&visited[1][x][y] == 0){
                    path n ={x,y,p.d+1,1};
                    que.push(n);
                }
            }
            else{
                if(board[x][y] == 0&&visited[1][x][y] == 0){
                    path n = {x,y,p.d+1,1};
                    que.push(n);
                }
            }
        }
    }
    cout<<"-1";
    return 0;
}