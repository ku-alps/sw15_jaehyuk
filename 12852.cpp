#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;cin>>N;
    int visited[1000001] = {0};
    vector<int> ans;
    queue<pair<pair<int,int>,int > > que;

    que.push(make_pair(make_pair(N,0),4));
    while(!que.empty()){
        int mtd = que.front().second;
        int idx = que.front().first.first;
        int dist = que.front().first.second;
        que.pop();
        
        if(visited[idx] != 0){
            continue;
        }
        visited[idx] = mtd;

        if(idx == 1){
            cout<<dist<<'\n';
            ans.push_back(1);
            while(idx != N){
                if(visited[idx] == 1){
                    idx = idx+1;
                    ans.push_back(idx);
                }
                else if(visited[idx] == 2){
                    idx = idx*2;
                    ans.push_back(idx);
                }
                else if(visited[idx] == 3){
                    idx = idx*3;
                    ans.push_back(idx);
                }
            }
            for(int i = 1; i<=ans.size(); i++){
                cout<<ans[ans.size()-i]<<" ";
            }
            break;
        }
        if(idx%2 == 0){
        if(visited[idx/2] == 0){
            que.push(make_pair(make_pair(idx/2,dist+1),2));
        }
        }
        if(idx%3 == 0){
        if(visited[idx/3] == 0){
            que.push(make_pair(make_pair(idx/3,dist+1),3));
        }
        }
        if(idx-1>=0){
        if(visited[idx-1] == 0){
            que.push(make_pair(make_pair(idx-1,dist+1),1));
        }
        }
    }
}