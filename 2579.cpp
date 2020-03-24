#include<iostream>
#include<vector>

using namespace std;
vector<int> stair;
vector<vector<int> > dp;

int main(){
    int N;
    cin>>N;
    stair.resize(301);
    dp.resize(301);
    for(int i = 0; i<301; i++){
        dp[i].resize(3);
    }

    for(int i = 0; i<N; i++){
        cin>>stair[i];
    }
    dp[0][0] = stair[0];
    dp[0][1] = 0;
    dp[1][0] = stair[1];
    dp[1][1] = dp[0][0]+stair[1];

    for(int i = 2; i<N; i++){
        dp[i][0] = max(dp[i-2][0],dp[i-2][1]) + stair[i];
        dp[i][1] = dp[i-1][0]+stair[i];
    }
    cout<<max(dp[N-1][0],dp[N-1][1])<<endl;
}