#include<bits/stdc++.h>

using namespace std;
int N,M,R;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
vector<vector<pair<int, int> > > board;
int main(){
    cin>>N>>M>>R;
    vector<int> items(N);
    vector<int> visited(N);
    board.resize(N);
    
    for(int i = 0; i<N; i++)
        cin>>items[i];
    int a,b,w;
    for(int i = 0; i<R; i++){
        cin>>a>>b>>w;
        board[a-1].push_back(make_pair(w,b-1));
        board[b-1].push_back(make_pair(w,a-1));
    }
    int _max = 0;
    for(int i = 0; i<N; i++){
       
        int temp = 0;
        fill(visited.begin(),visited.end(),0);
        pq.push(make_pair(i,0));

        while(!pq.empty()){
            pair<int,int> idx = pq.top();
            int node = idx.first;
            int val = idx.second;
            pq.pop();
            if(visited[node]==1){
                continue;
            }
            visited[node] = 1;
            temp+=items[node];

            for(int i = 0; i<board[node].size(); i++){
                if(visited[board[node][i].second]==0 && val+board[node][i].first<=M){
                    pq.push(make_pair(board[node][i].second,board[node][i].first+val));
                }
            }
        }
        if(temp>=_max)
            _max = temp;
    }
    cout<<_max;
}