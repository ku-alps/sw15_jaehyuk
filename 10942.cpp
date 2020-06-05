#include<iostream>
#include<cstring>
using namespace std;

int N,M;
int board[2000];
int dp[2000][2000];//dp[left][right] = 1 : palindrome

int func(int left, int right){
    if(left>=right)
        return 1;
    if(dp[left][right] != 0)
        return dp[left][right];
    if(board[left] == board[right])
        return dp[left][right] = func(left+1,right-1);   
    else
        return dp[left][right] = 0;
}
int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>board[i];
    }
    memset(dp,0,sizeof(dp));
    for(int l = 1; l<=N; l++){//길이
        for(int s = 0; s<N-l+1; s++){//시작점
            dp[s][s+l-1] = func(s,s+l-1);
        }
    }
    cin>>M;
    int s,e;
    for(int i = 0; i<M; i++){
        cin>>s>>e;
        cout<<dp[s-1][e-1]<<'\n';
    }
}