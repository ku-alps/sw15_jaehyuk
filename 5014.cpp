#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> floor;  //해당 층에 가는 최소 버튼의 수
vector<int> visited;
queue<int> que;
int F,S,G,U,D;

void BFS(){
    int btn = 0;
    while(!que.empty()){
        int idx = que.front();
        que.pop();
        btn = floor[idx]+1;
        for(int i = 1; idx+i*U<=F&&i==1; i++){
            if(visited[idx+i*U] == 0){
                visited[idx+i*U] = 1;
                floor[idx+i*U] = btn;
                que.push(idx+i*U);
            }
            else{
                if(floor[idx+i*U]>btn){
                    floor[idx+i*U] = btn;
                    que.push(idx+i*U);
                }
            }
        }
        for(int i = 1; idx-i*D>=1&&i==1; i++){
            if(visited[idx-i*D] == 0){
                visited[idx-i*D] = 1;
                floor[idx-i*D] = btn;
                que.push(idx-i*D);
            }
            else{
                if(floor[idx-i*D]>btn){
                    floor[idx-i*D] = btn;
                    que.push(idx-i*D);
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>F>>S>>G>>U>>D;

    floor.resize(F+1);
    visited.resize(F+1);
    fill(visited.begin(),visited.end(),0);
    fill(floor.begin(),floor.end(),-1);

    floor[S] = 0;
    visited[S] = 1;
    que.push(S);
    BFS();
    if(floor[G] != -1){
        cout<<floor[G];
    }
    else
    {
        cout<<"use the stairs";
    }
}