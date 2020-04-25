#include<bits/stdc++.h>
int P[10001];
int dp[10001];//i개 카드를 갖기위해 내야하는 최대금액
using namespace std;
int main(){
    int N;
    cin>>N;
    int mymax = 0;
    for(int i = 1; i<N+1; i++){
        cin>>P[i];
        dp[i] = P[i];
        // if(P[i]>mymax)
        //     mymax = P[i];
    }
    for(int i = 2; i<N+1; i++){
        for(int j = 1; j<i; j++){
            dp[i] = max(dp[i-j]+dp[j],dp[i]);
        }
    }
    cout<<dp[N];
}