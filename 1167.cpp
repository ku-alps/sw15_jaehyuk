#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int,int> > > arr;
vector<int> visited;
int V;
int leaf;
int _max=0;

int dfs(int idx,int len){
    if(visited[idx] == 1) return len;
    visited[idx] = 1;
    int temp = len;
    for(int i = 0; i<arr[idx].size(); i++){
        if(visited[arr[idx][i].first] == 0){
            temp = dfs(arr[idx][i].first,len+arr[idx][i].second);
        }
    }
    return temp;
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

    cout<<"?"<<dfs(0,0)<<endl;
    cout<<leaf<<" "<<_max<<endl;
    fill(visited.begin(),visited.end(),0);
    cout<<"?"<<dfs(leaf,0)<<endl;
    cout<<leaf<<" "<<_max<<endl;
}