#include<bits/stdc++.h>

using namespace std;

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int visited[100001][4] = {0};
    //visited[x][y] :
    // x -> 정해지지 않은 물의 양 y -> 0:물통1이 0, 1:물통2가 0, 2:물통1이 c, 3:물통2가 d
    //priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > que;
    queue<pair<int, pair<int, int> > > que;
    que.push(make_pair(0,make_pair(0,0)));
    que.push(make_pair(0,make_pair(0,1)));
    while(!que.empty()){
        //std::cout<<"?"<<endl;
        int dist = que.front().first;
        int x = que.front().second.first;
        int y = que.front().second.second;
        //cout<<"dist:"<<dist<<" "<<x<<" "<<y<<endl;
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
        
        if(y == 2){//물통 1이 a
            if(x == d && c == a){
                cout<<dist;
                return;
            }
        }
        if(y == 3){//물통 2가 b
            if(x == c && d == b){
                cout<<dist;
                return;
            }
        }
        if(visited[x][y] == 1)
            continue;
        visited[x][y] = 1;

        //FILL *2
        if(y==0){
            if(visited[x][2] == 0){
                que.push(make_pair(dist+1,make_pair(x,2)));
            }
            if(visited[b][0] == 0){
                que.push(make_pair(dist+1,make_pair(b,0)));
            }
        }
        else if(y==1){
            if(visited[x][3] == 0){
                que.push(make_pair(dist+1,make_pair(x,3)));
            }
            if(visited[a][1] == 0){
                que.push(make_pair(dist+1,make_pair(a,1)));
            }
        }
        else if(y==2){
            if(visited[a][3] == 0){
                que.push(make_pair(dist+1,make_pair(a,3)));
            }
        }else{
            if(visited[b][2] == 0){
                que.push(make_pair(dist+1,make_pair(b,2)));
            }
        }
        //MOVE *2
        
        if(y == 0){
            if(a<x){//물통1의 총 용량보다 물이 많음
                if(visited[x-a][2] == 0){
                    que.push(make_pair(dist+1,make_pair(x-a,2)));
                }
            }
            else{
                if(visited[x][1] == 0){
                    que.push(make_pair(dist+1,make_pair(x,1)));
                }
            }
        }
        else if(y == 1){//물통 2에 물이 0일 때 물통1에 있는 걸 물통2로 옮기자
            if(b<x){//물통2의 총 용량보다 물이 많음
                if(visited[x-b][3] == 0){
                    que.push(make_pair(dist+1,make_pair(x-b,3)));
                }
            }
            else{
                if(visited[x][0] == 0){
                    que.push(make_pair(dist+1,make_pair(x,0)));
                }
            }
        }
        else if(y == 2){//물통1은 이미 꽉 참 옮기는 경우만 하자.
            if(x+a>b){
                if(visited[(x+a)-b][3] == 0){
                    que.push(make_pair(dist+1,make_pair((x+a)-b,3)));
                }
            }
            else{
                if(visited[x+a][0] == 0){
                    que.push(make_pair(dist+1,make_pair(x+a,0)));
                }
            }
        }
        else{//물통2가 꽉참
            if(x+b>a){
                if(visited[(x+b)-a][2] == 0){
                    que.push(make_pair(dist+1,make_pair((x+b)-a,2)));
                }
            }
            else{
                if(visited[x+b][1] == 0){
                    que.push(make_pair(dist+1,make_pair(x+b,1)));
                }
            }
        }
        //POOR *2
        if(y==0){
            if(visited[0][0] == 0){
                que.push(make_pair(dist+1,make_pair(0,0)));
            }
            if(visited[0][1] == 0){
                que.push(make_pair(dist+1,make_pair(0,1)));
            }
        }
        else if(y==1){
            if(visited[0][0] == 0){
                que.push(make_pair(dist+1,make_pair(0,0)));
            }
            if(visited[0][1] == 0){
                que.push(make_pair(dist+1,make_pair(0,1)));
            }
        }
        else if(y==2){
            if(visited[x][0] == 0){
                que.push(make_pair(dist+1,make_pair(x,0)));
            }
            if(visited[a][1] == 0){
                que.push(make_pair(dist+1,make_pair(a,1)));
            }
        }
        else{
            if(visited[x][1] == 0){
                que.push(make_pair(dist+1,make_pair(x,1)));
            }
            if(visited[b][0] == 0){
                que.push(make_pair(dist+1,make_pair(b,0)));
            }
        }
    }
    cout<<"-1";
    return;
}
int main(){
    solve();
}
