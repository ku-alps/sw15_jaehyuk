#include<bits/stdc++.h>

using namespace std;
int M,N;
int arr[501][501] = {-1};
int dp[501][501] = {0};
int ans = 0;
priority_queue<pair<int,pair<int,int> > > que;
int dfs(int x,int y){
    if(x == M-1 && y == N-1){
        ans++;
        return 0;
    }
    if(x-1>= 0){
        if(arr[x-1][y] < arr[x][y]){
            dfs(x-1,y);
        }
    }
    if(x+1<=M-1){
        if(arr[x+1][y] < arr[x][y]){
            dfs(x+1,y);
        }
    }
    if(y-1>=0){
        if(arr[x][y-1] < arr[x][y]){
            dfs(x,y-1);
        }
    }
    if(y+1<=N-1){
        if(arr[x][y+1] < arr[x][y]){
            dfs(x,y+1);
        }
    }
    return 0;
}
void search(int x,int y){
    if(dp[x][y] == 0)
        return;
    
    if(x-1>=0){
        if(arr[x][y]>arr[x-1][y]){
            dp[x-1][y] += dp[x][y];
        }
    }
    if(y-1>=0){
        if(arr[x][y] > arr[x][y-1]){
            dp[x][y-1] += dp[x][y];
        }
    }
    if(x+1<=M-1){
        if(arr[x][y] > arr[x+1][y]){
            dp[x+1][y] += dp[x][y];
        }
    }
    if(y+1 <= N-1){
        if(arr[x][y] > arr[x][y+1]){
            dp[x][y+1] += dp[x][y];
        }
    }
}
int main(){
    cin>>M>>N;
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            cin>>arr[i][j];
            que.push(make_pair(arr[i][j],make_pair(i,j)));
        }
    }
    //dfs(0,0);
    while(que.top().first>=arr[0][0]){
        que.pop();
    }
    dp[0][0] = 1;
    search(0,0);
    while(!que.empty()){
        search(que.top().second.first,que.top().second.second);
        que.pop();
    }
    cout<<dp[M-1][N-1];
}