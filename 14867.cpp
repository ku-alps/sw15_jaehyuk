#include<bits/stdc++.h>

using namespace std;

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int visited[100001][4] = {0};
    //visited[x][y] :
    // x -> 정해지지 않은 물의 양 y -> 0:물통1이 0, 1:물통2가 0, 2:물통1이 a, 3:물통2가 b
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
        if(d == x){
            if(y == 2 && x == d){
                cout<<dist;
                return;
            }
        }
        if(c == 0){
            if(y == 1 && x == 0){
                cout<<dist;
                return;
            }
        }
        if(c == x){
            if(y == 3&& x == d){
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
