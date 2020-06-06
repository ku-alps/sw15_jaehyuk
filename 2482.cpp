#include<iostream>
#define MOD 1000000003
using namespace std;
long long dp[1001][1001];//인덱스, 선택 개수
int N,K;

int main(){
    cin>>N>>K;
    for(int i= 1; i<4; i++){
        dp[i][1] = i;
    }
    for(int i = 4; i<=N;i++){
        for(int j = 1; j<=i; j++){
            if(j==1){
                dp[i][j] = i;
            }
            else{
                dp[i][j] = (dp[i-2][j-1] + dp[i-1][j])%MOD;
            }
        }
    }
    cout<<dp[N][K];
}