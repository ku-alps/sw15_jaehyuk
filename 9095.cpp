#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> dp;
        dp.resize(N+5);
        fill(dp.begin(),dp.end(),0);
        dp[1] = 1,dp[2] = 1,dp[3] = 1;
        for(int i = 1; i<N+1; i++){
            dp[i+1] += dp[i];
            dp[i+2] += dp[i];
            dp[i+3] += dp[i];
        }
        cout<<dp[N]<<'\n';
    }
}