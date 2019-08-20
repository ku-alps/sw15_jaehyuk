#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int V,E;
vector<vector<int>> scc1;
vector<vector<int>> scc2;
vector<int> visited;
vector<int> stk;
vector<int> temp;
vector<vector<int>> ans;
int cnt = 0;

void dfs(int idx){
    if(visited[idx] == 1)
        return;
    visited[idx] = 1;
    
    for(int i = 0; i<scc1[idx].size(); i++){
        dfs(scc1[idx][i]);
    }
    stk.push_back(idx);
}
int rdfs(int idx){
    if(visited[idx] == 1)
        return 0;
    visited[idx] = 1;
    
    for(int i = 0; i<scc2[idx].size(); i++){
        rdfs(scc2[idx][i]);
    }
    temp.push_back(idx);
    return 1;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>V>>E;
    fill(visited.begin(),visited.end(),0);
    scc1.resize(V+1);
    scc2.resize(V+1);
    visited.resize(V+1);
    int a=0,b=0;
    for(int i = 0; i<E; i++){
        cin>>a>>b;
        a--;
        b--;
        scc1[a].push_back(b);
        scc2[b].push_back(a);
    }
    
    for(int i = 0; i<V; i++){
        dfs(i);
    }
    fill(visited.begin(),visited.end(),0);
    
    for(int i = (int)stk.size()-1; i>=0; i--){
        if(rdfs(stk[i]) == 1){
            sort(temp.begin(),temp.end(),less<int>());
            ans.push_back(temp);
            temp.clear();
        }
    }
    cout<<ans.size()<<'\n';
    sort(ans.begin(),ans.end());
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]+1<<" ";
        }
        cout<<"-1\n";
    }
}
