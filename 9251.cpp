#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > dp;
int main(){
    string str1,str2;
    cin>>str1>>str2;
    int l1 = str1.length(),l2 = str2.length();
    dp.resize(l1+1);
    for(int i = 0; i<l1+1; i++)
        dp[i].resize(l2+1);
    for(int i = 0; i<l2+1; i++)
        dp[0][i] = 0;
    for(int i = 0; i<l1+1; i++)
        dp[i][0] = 0;

    for(int i = 1; i<l1+1; i++){
        for(int j = 1; j<l2+1; j++){
            if(str1[i-1] == str2[j-1])  
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[l1][l2];
}