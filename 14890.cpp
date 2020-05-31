#include<iostream>

using namespace std;
int N,L;
int board[101][101];
int rroad[101][101] = {0};
int croad[101][101] = {0};
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool makeRoad(int &i, int &j, int d){
  int k = 0;
  while(k<L-1){  
    if(j>N-1 || i>N-1 || i< 0 || j<0){
      return false;
    }
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
        
    if(board[i][j] != board[i+dir[d][0]][j+dir[d][1]]){
      return false;
    }
    k++;
    i = i+dir[d][0];
    j = j+dir[d][1];
  }
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
  i = i-dir[d][0];
  j = j-dir[d][1];
  return true;
}
bool chk(int &i, int &j,int d){
    int k = 0;
    //cout<<d<<endl;
    if(board[i][j]<board[i+dir[d][0]][j+dir[d][1]]){
      if(d == 0){
        int x = i;
        int y = j;
        if(makeRoad(x,y,2)){
          return true;
        }
        return false;
      }
      if(d == 1){
        int x = i;
        int y = j;
        if(makeRoad(x,y,3)){
          return true;
        }
        return false;
      }
    }
    else if(board[i][j] == board[i+dir[d][0]][j+dir[d][1]]){
        return true;
    }
    else if(board[i][j] > 1+board[i+dir[d][0]][j+dir[d][1]]){
        return false;
    }
    
    i = i+dir[d][0];
    j = j+dir[d][1];
    
    if(makeRoad(i,j,d))
      return true;
    return false;
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
            cnt++;
            //cout<<"i: "<<i<<endl;
            continue;
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
            //cout<<"j: "<<j<<endl;
            continue;
        }
    }
    cout<<cnt<<endl;
}