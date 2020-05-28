#include<iostream>
using namespace std;
int N,M;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int board[50][50];
int visited[50][50] = {0};
int main(){
  cin>>N>>M;
  int r,c,d;
  for(int i = 0; i<N; i++){
    for(int j = 0; j<M; j++){
      cin>>board[i][j];
    }
  }
  int x = r;
  int y = c;
  visited[r][c] = 1;
  while(true){
    x = r;
    y = c;
    visited[r][c] = 1;
    d = (4-(d+1))%4; 
    x += dir[d][0];
    y += dir[d][1];  
    if(x>N-1||x<0 || y>M-1|| y<0){
      continue;
    }
    if(board[x][y] == 1 && visited[x][y] == 1){
      continue;
    }
    if(visited[x][y] == 0 && board[x][y] == 0){
      r = x;
      c = y;
    }
  }
}