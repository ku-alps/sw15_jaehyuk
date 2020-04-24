#include<bits/stdc++.h>

using namespace std;

pair<int,int> num[10];
string dp[51];

string mystrcmp(string a, string b){
    if(a.length() == 0){
        return b;
    }
    else if(b.length() == 0){
        return a;
    }
    if(a.length() == 0 && b.length() == 0){
        return "";
    }
    if(a.length()>0&&a[0] == '0'){
        if(b.length()>0&&b[0]=='0'){
        }
        else{
            return b;
        }
    }
    if(b.length()>0&&b[0] == '0'){
        if(a.length()>0&&a[0] == '0'){
        }
        else{
            return a;
        }
    }
    if(a.length()>b.length()){
        return a;
    }
    else if(a.length()<b.length()){
        return b;
    }
    else{
        int k = 0;
        while(k<a.length()){
            if((int)a[k]>(int)b[k]){
                return a;
            }
            else if((int)a[k]<(int)b[k]){
                return b;
            }
            else{
                k++;
                continue;
            }
        }
        return a;
    }
}

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first< b.first){
        return true;
    }
    else if(a.first>b.first){
        return false;
    }
    else{
        if(a.second > b.second){
            return true;
        }
        else 
            return false;
    }
}
int main(){
    long long result = 0;
    int N;cin>>N;
    int input;
    //num : first - 가격, second - 숫자
    
    for(int i = 0; i<N; i++){
        cin>>input;
        num[i].first = input;
        num[i].second = i;
    }
    sort(num,num+N,cmp);
    int K;cin>>K;
    
    for(int i = 0; i<K+1; i++){
        dp[i] = "";
    }
    for(int i = 0; i<N; i++){
        dp[num[i].first] = mystrcmp(dp[num[i].first],to_string(num[i].second));
    }
    
    for(int i = num[0].first+1; i<=K; i++){
        for(int j = 1; j<i; j++){
            //하나 또는 두개의 돈으로 수를 만들 수 없는 경우 -1
            if(dp[i-j]=="")
                dp[i] = mystrcmp(dp[i],dp[j]);
            else if(dp[j] == "")
                dp[i] = max(dp[i],dp[i-j]);
            else{
                if(dp[j].length()>0 && dp[j][0] == '0'){
                    if(dp[i-j].length()>0 && dp[i-j][0] == '0'){
                        dp[i] = mystrcmp(dp[i],"0");
                    }
                    else{
                        dp[i] = mystrcmp(dp[i],dp[i-j]+'0');
                    }
                }
                else if(dp[i-j].length()>0 && dp[i-j][0] == '0'){
                    dp[i] = mystrcmp(dp[i],dp[j]+'0');
                }
                else{
                    string temp = mystrcmp(dp[i-j]+dp[j],dp[j]+dp[i-j]);
                    dp[i] = mystrcmp(dp[i],temp);
                }
            }
        }
    }/*
    for(int i = 0; i<K+1; i++){
        cout<<i<<" : "<<dp[i]<<endl;
    }*/
    cout<<dp[K];
}