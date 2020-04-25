#include<bits/stdc++.h>
using namespace std;
long long dp[5001] = {0}; //i자리까지 경우의 수
//A : 1
//J : 10

//T : 20
//Z : 26

//이전 - 현재로 두자리 수 만드는경우
//현재로 한자리수 만드는경우
//현재 - 다음으로 두자리 수 만드는경우 <- 이건 할필요 없음

int main(){
    string str; cin>>str;
    if(str[0]-'0' == 0){
        cout<<0;
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<str.length()+1; i++){
        if(str[i-2] == '1' || (str[i-2] == '2'&&str[i-1]-'0'<=6))
            dp[i] += dp[i-2]%1000000;
        dp[i]%=1000000;
        if(str[i-1] != '0')
            dp[i] += dp[i-1]%1000000;
        dp[i]%=1000000;
    }   
    cout<<dp[str.length()];
}