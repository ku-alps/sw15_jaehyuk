#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
queue<pair<int,int> > que;

int main(){
    int n;cin>>n;
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
    int visited[101][101] = {0};
    for(int i = 0; i<n ;i++){
        for(int j = 0; j<n; j++){
            if(visited[i][j] == 1){
                continue;
            }
            que.push(make_pair(i,j));
            while(!que.empty()){
                pair<int,int> idx = que.front();
                que.pop();
                if(visited[idx.first][idx.second]==1){
                    continue;
                }
                visited[idx.first][idx.second] = 1;
                
                if(i-1>=0&&arr[i-1][j] == arr[i][j]){
                    que.push(make_pair(i-1,j));
                }
                if(i+1<=n-1&&arr[i+1][j] == arr[i][j]){
                    que.push(make_pair(i+1,j));
                }
                if(j-1>=0&&arr[i][j-1] == arr[i][j]){
                    que.push(make_pair(i,j-1));
                }
                if(j+1<=n-1&&arr[i][j+1] == arr[i][j]){
                    que.push(make_pair(i,j+1));
                }
            }
            cnt++;
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
            if(visited[i][j] == 1){
                continue;
            }
            que.push(make_pair(i,j));
            while(!que.empty()){
                pair<int,int> idx = que.front();
                que.pop();
                if(visited[idx.first][idx.second]==1){
                    continue;
                }
                visited[idx.first][idx.second] = 1;
                if(i-1>=0&&arr[i-1][j] == arr[idx.first][idx.second]){
                    que.push(make_pair(i-1,j));
                }
                if(i+1<=n-1&&arr[i+1][j] == arr[idx.first][idx.second]){
                    que.push(make_pair(i+1,j));
                }
                if(j-1>=0&&arr[i][j-1] == arr[idx.first][idx.second]){
                    que.push(make_pair(i,j-1));
                }
                if(j+1<=n-1&&arr[i][j+1] == arr[idx.first][idx.second]){
                    que.push(make_pair(i,j+1));
                }
            }
            cnt2++;
        }
    }
    cout<<cnt<<" "<<cnt2;
}