#include<bits/stdc++.h>

using namespace std;
int N;
long long ans;
long long dp[101][10] = {0};
//길이가 i이고 마지막 i번째 수가 j인 수의 계단수 개수
int main(){
    cin>>N;
    for(int i = 1; i<10; i++)
        dp[1][i] = 1;
    //모든 길이에 대해서
    for(int i = 1; i<N+1; i++){
        for(int j = 0; j<10; j++){
            if(j == 0){
                dp[i+1][j] += dp[i][1]%1000000000;
                dp[i+1][j] %=1000000000;
            }else if(j == 9){
                dp[i+1][j] += dp[i][8]%1000000000;
                dp[i+1][j] %=1000000000;
            }
            else{
                dp[i+1][j] += (dp[i][j-1]%1000000000+dp[i][j+1]%1000000000)%1000000000;
                dp[i+1][j] %=1000000000;
            }
        }
    }
    long long sum = 0;
    for(int i = 0; i<10; i++){
        sum+= dp[N][i]%1000000000;
        sum%=1000000000;
    }
    cout<<sum;
}