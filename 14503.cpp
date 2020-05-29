#include<iostream>
using namespace std;
int N,M;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int board[50][50];
int visited[50][50] = {0};
int main(){
  cin>>N>>M;
  int r,c,d;
  cin>>r>>c>>d;
  for(int i = 0; i<N; i++){
    for(int j = 0; j<M; j++){
      cin>>board[i][j];
    }
  }
  int x = r;
  int y = c;
  visited[r][c] = 1;
  int cnt = 0;
  int k = 0;
  while(true){
    k++;
    x = r;
    y = c;
    
    //cout<<r<<" "<<c<<" "<<d<<endl;
    visited[r][c] = 1;

    if(
      (visited[x+dir[0][0]][y+dir[0][1]]==1||
      board[x+dir[0][0]][y+dir[0][1]] == 1)&&
      (visited[x+dir[1][0]][y+dir[1][1]]==1||
      board[x+dir[1][0]][y+dir[1][1]] == 1)&&
      (visited[x+dir[2][0]][y+dir[2][1]]==1||
      board[x+dir[2][0]][y+dir[2][1]] == 1)&&
      (visited[x+dir[3][0]][y+dir[3][1]]==1||
      board[x+dir[3][0]][y+dir[3][1]] == 1)
    ){
      r -= dir[d][0];
      c -= dir[d][1];
      
      if(board[r][c] == 1){
        for(int i = 0; i<N; i++){
          for(int j = 0; j<M; j++){
            cnt+=visited[i][j];
          }
        }
        cout<<cnt<<endl;
        return 0;
      }
      
      continue;
    }
    //3->2
    //2->1
    //1->0
    //0->3
    int left;
    if(d== 0){
      left = 3;
    }
    else{
      left = d-1;
    }
    //int left = (4-abs(d-1))%4; 
    x += dir[left][0];
    y += dir[left][1];

     if(x>N-1||x<0 || y>M-1|| y<0){
       x -=dir[left][0];
       y -=dir[left][1];
       continue;
     }
    if(board[x][y] == 0 && visited[x][y] == 0){
      r = x;
      c = y;
      d = left;
      continue;
    }
    if(board[x][y] == 1 || visited[x][y] == 1){
      d = left;
      continue;
    }
    
  }
}