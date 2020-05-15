#include <iostream>
using namespace std;
int n,m; 
int arr[501][501];
int isOk(int r,int c,int shape){
  int sum = -1;
  switch(shape){
    case 0:{//1*4
      if(c+3<m){
        sum = max(sum,arr[r][c]+arr[r][c+1]+arr[r][c+2]+arr[r][c+3]);
      }
      if(r+3<n){
        sum = max(sum,arr[r][c]+arr[r+1][c]+arr[r+2][c]+arr[r+3][c]);
      }
      break;
    }
    case 1:{
      if(c+1<m&&r+1<n){
        sum = max(sum,arr[r][c] + arr[r+1][c+1] + arr[r][c+1] + arr[r+1][c]);
      }
      break;
    }
    case 2:{
      if(c+1<m && r+2<n){
        sum = max(sum,arr[r][c] + arr[r+1][c] + arr[r+2][c]+arr[r+2][c+1]);
        sum = max(sum,arr[r][c]+arr[r][c+1]+arr[r+1][c+1]+arr[r+2][c+1]);
        sum = max(sum,arr[r][c+1]+arr[r+1][c+1]+arr[r+2][c+1] + arr[r+2][c]);
        sum = max(sum,arr[r][c]+arr[r][c+1]+arr[r+1][c]+arr[r+2][c]);
      }
      if(c+2<m && r+1<n){
        sum = max(sum,arr[r][c]+arr[r+1][c]+arr[r][c+1]+arr[r][c+2]);
        sum = max(sum,arr[r+1][c]+arr[r+1][c+1]+arr[r+1][c+2]+arr[r][c+2]);
        sum = max(sum,arr[r][c]+arr[r][c+1]+arr[r][c+2]+arr[r+1][c+2]);
        sum = max(sum,arr[r][c]+arr[r+1][c]+arr[r+1][c+1]+arr[r+1][c+2]);
      }
      break;
    }
    case 3:{
      if(c+1<m && r+2<n){
        sum = max(sum,arr[r][c] + arr[r+1][c] + arr[r+1][c+1]+arr[r+2][c+1]);
        sum = max(sum,arr[r][c+1]+arr[r+1][c+1]+arr[r+1][c]+arr[r+2][c]);
      }
      if(c+2<m && r+1<n){
        sum = max(sum,arr[r+1][c]+arr[r+1][c+1]+arr[r][c+1]+arr[r][c+2]);
        sum = max(sum, arr[r][c]+arr[r][c+1]+arr[r+1][c+1]+arr[r+1][c+2]);
      }
      break;
    }
    case 4:{
      if(c+2<m && r+1<n){
        sum = max(sum,arr[r][c]+arr[r][c+1]+arr[r][c+2]+arr[r+1][c+1]);
        sum = max(sum,arr[r+1][c]+arr[r+1][c+1]+arr[r][c+1]+arr[r+1][c+2]);
      }
      if(c+1<m && r+2<n){
        sum = max(sum,arr[r][c]+arr[r+1][c]+arr[r+2][c]+arr[r+1][c+1]);
        sum = max(sum,arr[r][c+1]+arr[r+1][c+1]+arr[r+1][c]+arr[r+2][c+1]);
      }
      break;
    }
  }
  return sum;
}
int main(){
  cin>>n>>m;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      cin>>arr[i][j];
    }
  }
  int sum = 0;
  for(int i= 0; i<n; i++){
    for(int j = 0; j<m; j++){
      for(int k = 0; k<=4; k++){
        sum = max(sum,isOk(i,j,k));
      }
    }
  }
  cout<<sum<<endl;
}