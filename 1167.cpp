#include <vector>
#include<iostream>

using namespace std;
vector<vector<pair<int,int> > > arr;
vector<int> visited;
int V;
int leaf;
int _max=0;

pair<int,int> dfs(int idx,int len){
    if(visited[idx] == 1)
        return make_pair(idx, 0);
    visited[idx] = 1;
    
    pair<int,int> temp = make_pair(idx,len);
    if(_max<temp.second){
        _max = temp.second;
        leaf = temp.first;
    }
    for(int i = 0; i<arr[idx].size(); i++){
        if(visited[arr[idx][i].first] == 0){
            temp = dfs(arr[idx][i].first,len+arr[idx][i].second);
            
        }
    }
    return make_pair(leaf,_max);
}

int main()
{
    cin>>V;
    int input = 0;
    int input2 = 0;
    int vertex = 0;
    arr.resize(V+1);
    visited.resize(V+1);
    fill(visited.begin(),visited.end(),0);
    for(int i = 0; i<V; i++){
        cin>>vertex;
        while(true){
            cin>>input;
            if(input == -1){
                break;
            }
            cin>>input2;
            arr[vertex].push_back(make_pair(input,input2));
        }
    }
    
    dfs(vertex,0).first;
    //cout<<leaf<<" "<<_max<<endl;
    fill(visited.begin(),visited.end(),0);
    _max = 0;
    dfs(leaf,0).first;
    //cout<<leaf<<" "<<_max<<endl;
    cout<<_max;
}
