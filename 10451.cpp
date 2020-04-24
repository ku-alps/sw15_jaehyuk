#include<bits/stdc++.h>
using namespace std;
int N,T;
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        vector<vector<int> > arr;
        vector<int> visited;
        queue<int> que;
        arr.resize(N+1);
        for(int i = 0; i<N+1; i++){
            arr[i].resize(1);
        }
        visited.resize(N+1);
        fill(visited.begin(),visited.end(),0);
        for(int i = 0; i<N; i++){
            int input;
            cin>>input;
            arr[i+1][0] = input;
        }
        int cnt = 0;
        for(int i = 1; i<=N; i++){
            if(visited[i] == 1){
                continue;
            }
            que.push(i);
            while(!que.empty()){
                int idx = que.front();
                que.pop();
                if(visited[idx] == 1){
                    cnt++;
                    break;
                }
                visited[idx] = 1;
                que.push(arr[idx][0]);
            }
        }
        cout<<cnt<<endl;
    }
}