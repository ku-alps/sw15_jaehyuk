#include<bits/stdc++.h>
#include<limits.h>

using namespace std;
int A[11];

//dp : k원을 만드는데 필요한 동전 갯수의 최솟값
int dp[10000] = {INT_MAX};
int main(){
    int N,K;
    cin>>N>>K;
    for(int i = 0; i<N; i++){
        cin>>A[i];
    }
    int min_cnt = INT_MAX;
    for(int i = N-1; i>=0; i--){
        int temp = K;
        int cnt = 0;
        int j = i;
        while(temp > 0){
            cnt+= temp/A[j];
            temp = temp%A[j];
            j--;
        }
        if(min_cnt>cnt){
            min_cnt = cnt;
        }
    }
    cout<<min_cnt;
}