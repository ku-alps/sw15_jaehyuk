#include<bits/stdc++.h>

using namespace std;
int dp[1000][1000];
vector<char> ans;
int N;
string A;
string B;

int main(){
    cin>>A>>B;
    //cout<<A<<endl<<B<<endl;
    for(int i = 0; i<A.length(); i++){
        dp[i][0] = 0;
        if(B[0] == A[i]){
            dp[i][0] = 1;
        }
        if(i>=1 && dp[i-1][0] == 1){
            dp[i][0]=1;
        }
    }
    for(int i = 0; i<B.length(); i++){
        dp[0][i] = 0;
        if(A[0] == B[i]){
            dp[0][i] = 1;
        }
        if(i>=1 && dp[0][i-1] == 1){
            dp[0][i]=1;
        }
    }
    for(int i = 1; i<A.length(); i++){
        for(int j = 1; j<B.length(); j++){
            if(A[i] == B[j]){
                dp[i][j] = max(dp[i-1][j-1]+1,max(dp[i][j-1], dp[i-1][j]));
            }
            else{
                dp[i][j] = max(dp[i-1][j-1],max(dp[i][j-1], dp[i-1][j]));
            }
        }
    }
    int result = dp[A.length()-1][B.length()-1];
    if(result == 0){
        cout<<0;
        return 0;
    }/*
    for(int i = 0; i<A.length(); i++){
        for(int j = 0; j<B.length(); j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[A.length()-1][B.length()-1]<<'\n';

    int cnt = result;

    int i = A.length()-1;
    int j = B.length()-1;
    while(cnt!= 0){
        
        if(i-1>=0 && dp[i][j] == dp[i-1][j]){
            i--;
        }
        else if(j-1>=0 && dp[i][j] == dp[i][j-1]){
            j--;
        }
        else{
            ans.push_back(A[i]);
            i--;
            j--;
            cnt--;
        }
        
    }
    for(int i = ans.size()-1; i>=0; i--){
        cout<<ans[i];
    }
}