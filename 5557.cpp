#include<iostream>
#include<vector>

using namespace std;
long long n;
long long cnt = 0;

vector<long long> num;
long long** memo;

long long dfs(long long cur,long long idx){
    
    if(idx == n-1){
        if(num[idx] == cur){
            memo[cur][idx] ++;
            cnt++;
            return 1;
        }
        else
            return 0;
    }
    if(memo[cur][idx] != 0){
        cnt+=memo[cur][idx];
        return memo[cur][idx];
    }
    if(cur-num[idx]>=0 && cur+num[idx] <=20)
    {
        memo[cur][idx] += dfs(cur-num[idx],idx+1);
        memo[cur][idx] += dfs(cur+num[idx],idx+1);
        return memo[cur][idx];
    }
    else if(cur-num[idx] >=0 ){
        memo[cur][idx]+=dfs(cur-num[idx],idx+1);
        return memo[cur][idx];
    }
    else if(cur+num[idx] <= 20){
        memo[cur][idx] += dfs(cur+num[idx], idx+1);
        return memo[cur][idx];
    }
    else
        return 0;
}

int main(){
    cin>>n;
    memo = new long long*[1001];
    for(long long i = 0; i<1001; i++){
        memo[i] = new long long[101];
    }
    for(long long i = 0; i<1001; i++){
        for(long long j = 0; j<101; j++)
            memo[i][j] = 0;
    }
    
    num.resize(n);  //숫자저장 배열
  
    for(long long i = 0; i<n; i++){
        cin>>num[i];
    }
    dfs(num[0],1);
    cout<<cnt<<endl;
//    cout<<memo[num[0]][1]<<endl;
}
