#include<bits/stdc++.h>

using namespace std;

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int visited[100001][4] = {0};
    //visited[x][y] :
    // x -> 정해지지 않은 물의 양 y -> 0:물통1이 0, 1:물통2가 0, 2:물통1이 c, 3:물통2가 d
    queue<pair<int,pair<int,int> > > que;
    que.push(make_pair(0,make_pair(0,0)));
    que.push(make_pair(0,make_pair(0,1)));
    while(!que.empty()){
        //std::cout<<"?"<<endl;
        int dist = que.front().first;
        int x = que.front().second.first;
        int y = que.front().second.second;
        que.pop();
        if(y == 0){//물통 1이 0
            if(c == 0 && d == x){
                cout<<dist;
                return;
            }
        }
        if(y == 1){//물통 2가 0이 목표일때
            if(d == 0 && x == c){
                cout<<dist;
                return;
            }
        }
        
        if(y == 2){//물통 1이 c
            if(x == d){
                cout<<dist;
                return;
            }
        }
        if(y == 3){//물통 2가 d
            if(x == c){
                cout<<dist;
                return;
            }
        }

        if(visited[x][y] == 1)
            continue;
        visited[x][y] = 1;

        //FILL *2
        if(visited[x][2] == 0){
            que.push(make_pair(dist+1,make_pair(x,2)));
        }
        if(visited[x][3] == 0){
            que.push(make_pair(dist+1,make_pair(y,3)));
        }
        //MOVE *2
        
        int mx2;
        int temp;
        if(y == 0){
            temp = 0;
            if(visited[temp][0])
        }
        else if(y == 1){
            temp = 0;
        }
        else if(y == 2){
            temp = c;
        }
        else{
            temp = d;
        }

        //POOR *2
        if(visited[x][0] == 0){
            que.push(make_pair(dist+1,make_pair(x,0)));
        }
        if(visited[y][1] == 0){
            que.push(make_pair(dist+1,make_pair(y,1)));
        }
    }
    cout<<"-1";
    return;
}
int main(){
    solve();
}
