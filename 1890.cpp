#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
long long dp[101][101] ={0};
int N;

int main(){
    cin>>N;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            cin>>arr[i][j];
    dp[0][0] = 1;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(dp[i][j] == 0 || (i == N-1 && j ==N-1)){
                continue;
            }
            if(j+arr[i][j]<N){
                dp[i][j+arr[i][j]] += dp[i][j];
            }
            if(i+arr[i][j]<N){
                dp[i+arr[i][j]][j] += dp[i][j];
            }
        }
    }
    cout<<dp[N-1][N-1];
}
