#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

vector<int> dp(3000001,1000001);
int main(){
    int N;cin>>N;
    dp[1] = 0;
    //K를 만들 때 사용한 연산의 최소 수
    for(int i = 1; i<N+1; i++){
        dp[i*3] = min(dp[i*3],dp[i]+1);
        dp[i*2] = min(dp[i*2],dp[i]+1);
        dp[i+1] = min(dp[i+1],dp[i]+1);     
    }
    cout<<dp[N];
}