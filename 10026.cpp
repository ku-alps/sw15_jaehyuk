#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
queue<pair<int,int> > que;
int visited[101][101]={0};
int n;
int bfs(int i,int j){
    int cnt = 0;
    que.push(make_pair(i,j));
    while(!que.empty()){
        pair<int,int> idx = que.front();
        que.pop();
        int x = idx.first;
        int y = idx.second;
        if(visited[x][y]==1){
            continue;
        }
        visited[x][y] = 1;
                
        if((x-1>=0&&arr[x-1][y] == arr[x][y])&&visited[x-1][y] == 0){
            que.push(make_pair(x-1,y));
        }
        if((x+1<=n-1&&arr[x+1][y] == arr[x][y])&&visited[x+1][y] == 0){
            que.push(make_pair(x+1,y));
        }
        if((y-1>=0&&arr[x][y-1] == arr[x][y])&&visited[x][y-1] == 0){
            que.push(make_pair(x,y-1));
        }
        if((y+1<=n-1&&arr[x][y+1] == arr[x][y])&&visited[x][1+y] == 0){
            que.push(make_pair(x,y+1));
        }
        cnt++;
    }
    return cnt;
}

int main(){
    cin>>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            char input;
            cin>>input;
            if(input=='R'){
                arr[i][j] = 0;
            }
            else if(input == 'G'){
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = 2;
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i<n ;i++){
        for(int j = 0; j<n; j++){
            
            if(bfs(i,j)>0){
                cnt++;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(arr[i][j] == 0){
                arr[i][j] = 1;
            }
        }
    }
    
    int cnt2 = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            visited[i][j] = 0;
        }
    }
    for(int i = 0; i<n ;i++){
        for(int j = 0; j<n; j++){
            if(bfs(i,j)>0){
                cnt2++;
            }
        }
    }
    cout<<cnt<<" "<<cnt2;
}