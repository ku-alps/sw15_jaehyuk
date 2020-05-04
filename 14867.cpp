#include<bits/stdc++.h>

using namespace std;

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int visited[100001][4] = {0};
    queue<pair<int,pair<int,int> > > que;
    que.push(make_pair(0,make_pair(0,0)));
    que.push(make_pair(0,make_pair(0,1)));
    while(!que.empty()){
        //std::cout<<"?"<<endl;
        int dist = que.front().first;
        int x = que.front().second.first;
        int y = que.front().second.second;
        que.pop();
        if(d == 0){
            if(y == 0 && x == c){
                cout<<dist;
                return;
            }
        }
        if(d == b){
            if(y == 2 && x == c){
                cout<<dist;
                return;
            }
        }
        if(c == 0){
            if(y == 1 && y == d){
                cout<<dist;
                return;
            }
        }
        if(c == a){
            if(y == 3&& y == d){
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
        if(visited[y][3] == 0){
            que.push(make_pair(dist+1,make_pair(y,3)));
        }
        //MOVE *2
        
        int mx2;
        int mx = min(a,y+x);
        if(mx == a){
            mx2 = y+x-a;
            if(visited[mx2][3]==0){
                que.push(make_pair(dist+1,make_pair(mx2,3)));
            }
        }
        else{
            mx2 = 0;
            if(visited[mx][0]==0){
                que.push(make_pair(dist+1,make_pair(mx,0)));
            }
        }
        int my2;
        int my = min(b,y+x);
        if(my == b){
            my2 = y+x-b;
            if(visited[my2][2]==0){
                que.push(make_pair(dist+1,make_pair(my2,2)));
            }
        }
        else{
            my2 = 0;
            if(visited[my][1]==0){
                que.push(make_pair(dist+1,make_pair(my,1)));
            }
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
