//1967 트리의 지름

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int n;
int visited[10000] = {0};
int edge[10000][10000] = {0};
//deque<int> radius[10000];
int rad[10000][10000] = {0};

int dfs(int node,int dist){
    if(visited[node] == 1)
        return dist;
    int cnt = 0;
    
    visited[node] = 1;
    
    for(int i = 0; i<n; i++){
        if(edge[node][i] > 0 && visited[i] <= 0){
            rad[node][i] = dfs(i,edge[node][i]);
        }
    }
   
    int localmax = 0;
    for(int i = 0; i<n; i++){
        cnt += rad[node][i];
    
        if(localmax < rad[node][i])
            localmax = rad[node][i];
    }
    if(cnt == 0)
        return dist;
    else
        return dist+localmax;
}

int main(){
    cin>>n;
    int p,c,w;
    for(int i = 0; i<n-1; i++){
        cin>>p>>c>>w;
        edge[p-1][c-1] = w;
        edge[c-1][p-1] = w;
    }
    dfs(0,0);
    //radius.resize(n);
    /*
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<edge[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<rad[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int total = 0;
    int localmax = 0;
    int a ,b;

    
    
    cout<<total<<endl;
}
