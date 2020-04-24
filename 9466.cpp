#include<bits/stdc++.h>

using namespace std;

int arr[100001];
int visited[100001];
int ans[100001];
pair<int,int> dfs(int idx){
    if(ans[idx] == 1)
        return make_pair(idx,0);
    if(ans[idx] == 2)
        return make_pair(idx,0);
    if(visited[idx] == 1){
        ans[idx] = 1;
        return make_pair(idx,1);
    }
    visited[idx] = 1;

    pair<int,int> res = dfs(arr[idx]);
    if(res.first == idx && res.second == 1){
        ans[idx] = 1;
        return make_pair(idx,0);
    }
    else if(res.first != idx && res.second == 1){
        ans[idx] = 1;
        return make_pair(res.first,1);
    }
    else{
        ans[idx] = 2;
        return make_pair(idx, 0);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        int input;
        for(int i = 0; i<N; i++){
            cin>>input;
            input--;
            arr[i] = input;
        }
        fill(ans,ans+N,0);
        fill(visited,visited+N,0);
        for(int i = 0; i<N; i++){
            dfs(i);
        }
        int sum = 0;
        for(int i = 0; i<N; i++){
            if(ans[i] == 0||ans[i] == 2)
                sum++;
        }
        cout<<sum<<'\n';
    }
}