#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int T,N;
vector<pair<int,int> > arr;
vector<int> visited;

bool enable(pair<int,int> a,pair<int,int> b){
    if(abs(a.first-b.first)+abs(a.second-b.second)<=1000)
        return true;
    return false;  
}

int DFS(int node){
    visited[node] = 1;
    if(node == N+1)
        return 1;
    for(int i = 0; i<N+2; i++)
        if(visited[i] == 0 && enable(arr[node],arr[i]))
            if(DFS(i) == 1)
                return 1;
    return 0;
}
int main(){
    cin>>T;
    
    while(T--){
        cin>>N;
        arr.resize(N+2);
        visited.resize(N+2);
        fill(visited.begin(),visited.end(),0);
        for(int i = 0 ; i<N+2; i++)
            cin>>arr[i].first>>arr[i].second;
        if(DFS(0) == 1)
            cout<<"happy"<<'\n';
        else
            cout<<"sad"<<'\n';
    }
}