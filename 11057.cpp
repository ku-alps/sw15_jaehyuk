#include<iostream>

using namespace std;

int n;
int dp[1001][10];

int main(){
    cin>>n;
    for(int i = 0; i<10; i++){
        dp[0][i] = 1;
    }
    
    //dp의 정의 : @으로 끝나는 것
    
    for(int i = 1; i<n; i++){
        for(int j = 0; j<10; j++){
            if(j == 0)
                dp[i][0] = dp[i-1][0]%10007;
            else
                dp[i][j] = dp[i][j-1]%10007+dp[i-1][j]%10007;
        }
    }
    
    int sum = 0;
    for(int i = 0; i<10; i++){
        sum += dp[n-1][i]%10007;
    }
    cout<<sum%10007<<endl;
/*
    dp[n][0] = dp[n-1][0];
    dp[n][1] = dp[n-1][0]+dp[n-1][1];
    dp[n][2] = dp[n-1][0]+dp[n-1][1]+dp[n-1][2];
    
    dp[n][9] = dp[n][8]+dp[n-1][9]
 */
}
