#include<iostream>
using namespace std;

int N;
int input[5000];
int arr[5000][5000];

int dp(int left,int right){
    if(left>=right){
        return 0;
    }
    if(arr[left][right] != -1){
        return arr[left][right];
    }

    if(input[left] == input[right]){    //추가 X
        arr[left][right] = dp(left+1, right-1);
        return arr[left][right];
    }
    else{   //1 추가
        arr[left][right] = min(dp(left+1,right), dp(left,right-1))+1;
        return arr[left][right];
    }
}
int main(){
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>input[i];
    }
    for(int i= 0; i<N; i++){
        for(int j = 0; j<N; j++){
            arr[i][j] = -1;
        }
    }
    dp(0,N-1);
    cout<<arr[0][N-1];
    
}