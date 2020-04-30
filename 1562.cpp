#include<bits/stdc++.h>
#define MOD 1000000000
using namespace std;
long long dp[101][10][1<<10];

int main(){
    int N;
    cin>>N;
    dp[1][0][1<<0] = 0;
    for(int i = 1; i<=9 ;i++){
        dp[1][i][1<<i] = 1;
    }
    for(int i = 2; i<=N; i++){
        for(int k = 0; k<(1<<10); k++)
            dp[i][0][k | (1<<0)] += dp[i-1][1][k]%MOD;
        for(int k = 0; k<(1<<10); k++)
            dp[i][9][k | (1<<9)] += dp[i-1][8][k]%MOD;
        for(int j = 1; j<9; j++){
            for(int k = 0; k<(1<<10); k++){
                dp[i][j][k | (1<<j)] += dp[i-1][j-1][k]%MOD;
                dp[i][j][k | (1<<j)] += dp[i-1][j+1][k]%MOD;
            }
        }
    }
    long long sum = 0;
    for(int i = 0; i<10; i++){
        sum += dp[N][i][(1<<10)-1]%MOD;
        sum %= MOD;
    }
    cout<<sum;
}