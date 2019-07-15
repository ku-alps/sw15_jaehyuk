#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> visited;
vector<vector<int>> arr;
queue<pair<int,int>> que;
void bfs(int p){
    while(!que.empty()){
        int idx = que.front().first;
        int cnt = que.front().second;
        
        if(visited[idx] == 1){
            que.pop();
            continue;
        }
        visited[idx] = 1;
        if(idx == p){
            cout<<cnt<<endl;
            return;
        }
        que.pop();
        
        for(int i = 0; i<arr[idx].size(); i++){
            que.push(make_pair(arr[idx][i],cnt+1));
        }
        if(arr[idx].size() == 0)
            continue;
    }
    cout<<"-1"<<endl;
}
int main(){
    int n;
    int x,y;
    
    cin>>n;
    cin>>x>>y;
    int k = 0;
    cin>>k;
    int p,c;
    arr.resize(n);
    visited.resize(n);
    fill(visited.begin(),visited.end(),0);
    
    for(int i = 0; i<k; i++){
        cin>>p>>c;
        
        arr[p-1].push_back(c-1);
        arr[c-1].push_back(p-1);
    }
    que.push(make_pair(x-1,0));
    bfs(y-1);
}
