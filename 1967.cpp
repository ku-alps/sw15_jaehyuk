//1967 트리의 지름

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct edge{
    int from;
    int weight;
    int to;
    edge(int from,int to,int weight):from(from),weight(weight),to(to){};
};
vector<int> visited;
vector<vector<edge*>> adj;
void create_edge(int from, int to,int weight){
    edge* edge1 = new edge(from,to,weight);
    adj[from].push_back(edge1);
}
pair<int,int> dfs(int node,int dist){
    
    visited[node] = 1;
    pair<int,int> localmax = make_pair(node,0);
    //pair<int,int> curmax = make_pair(node,dist);
    
    for(int i = 0; i<adj[node].size(); i++){
        if(visited[adj[node][i]->to] == 0){
            pair<int,int> temp;
            temp = dfs(adj[node][i]->to,adj[node][i]->weight);
            
            if(localmax.second < temp.second){
                localmax = temp;
            }
        }
    }
    localmax.second+= dist;
    return localmax;
}

int main(){
    cin>>n;
    adj.resize(n);
    visited.resize(n);
    fill(visited.begin(),visited.end(),0);
    
    int p,c,w;
    for(int i = 0; i<n-1; i++){
        cin>>p>>c>>w;
        create_edge(p-1,c-1,w);
        create_edge(c-1,p-1,w);
    }
    /*
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<adj[i].size(); j++){
            cout<<" "<<adj[i][j]->to<<" ";
        }
        cout<<endl;
    }*/
    pair<int,int> _max = dfs(0,0);
    //cout<<_max.first<<" "<<_max.second<<endl;
    
    fill(visited.begin(),visited.end(),0);
    
    pair<int,int> final_max = dfs(_max.first,0);
    cout<<final_max.second<<endl;
}
