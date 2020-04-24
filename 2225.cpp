#include<bits/stdc++.h>

using namespace std;
int N,K;
long long dp[201][201] = {0};
int main(){
    cin>>N>>K;
    //K개를 더해서 합이 N이 되는경우의수
    for(int i = 0; i<=N; i++){
        dp[i][1] = 1;
    }
    for(int i = 1; i<=K; i++){
        for(int j = 0; j<=N; j++){
            for(int k = 0; k<=j; k++){
                dp[j][i] += dp[j-k][i-1]%1000000000;
                dp[j][i] %= 1000000000;
            }
        }
    }
    std::cout<<dp[N][K];
}