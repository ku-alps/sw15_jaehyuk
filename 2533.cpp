#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int N;
vector<vector<int> > arr;
int visited[1000001];
int dp[2][1000001];//x=1 해당 노드가 얼리어답터, x=0 해당 노드가 얼리어답터가 아님
int dfs(int idx){
    if(visited[idx] == 1)
        return -1;
    visited[idx] = 1;

    if(arr[idx].size() == 1 && visited[arr[idx][0]] == 1){
        dp[1][idx] = 1; //리프이고, 노드가 하나이기 때문에 얼리어답터여야함
        dp[0][idx] = 0; //리프 노드가 얼리어답터가 아니면 해당 노드아래로 얼리어답터 0개
        return 0;
    }
    dp[1][idx] = 1;
    for(int i = 0; i<arr[idx].size(); i++){
        if(dfs(arr[idx][i])!=-1){
            dp[0][idx] += dp[1][arr[idx][i]];
            dp[1][idx] += min(dp[0][arr[idx][i]],dp[1][arr[idx][i]]);
        }
    }
    return 0;
}
int main(){
    cin>>N;
    arr.resize(N+1);
    memset(visited,0,sizeof(visited));
    memset(dp,0,sizeof(dp));
    int s,e;
    for(int i = 0; i<N-1; i++){
        cin>>s>>e;
        arr[s-1].push_back(e-1);
        arr[e-1].push_back(s-1);
    }
    if(N == 2){
        cout<<1;
        return 0;
    }
    dfs(0);
    cout<<min(dp[0][0],dp[1][0]);
    return 0;
}