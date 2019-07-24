#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct node{
    int num;
    int r;
    int c;
    int dist;
};

int r,c;
int** board;
int** visited;
node** ans;
int* visited2;

bool cmp(node &a,node &b){
    return a.dist<b.dist;
}
vector<vector<vector<node>>> park;
vector<node> car;
vector<vector<node>> car2;
queue<node> que;

int bipartite(int n){

    if(visited2[n] == 1){
        return 0;
    }
    visited2[n] = 1;
    
    for(int i = 0; i<car2[n].size(); i++){
        if(ans[car2[n][i].r][car2[n][i].c].dist == -1){
            ans[car2[n][i].r][car2[n][i].c] = car2[n][i];
            //return car2[n][i].dist;
            return 1;
        }
        else
        {
            if(bipartite(ans[car2[n][i].r][car2[n][i].c].num) != 0){
                ans[car2[n][i].r][car2[n][i].c] = car2[n][i];
                //return max(car2[n][i].dist,car2[n].begin()->dist);
                return 1;
            }
        }
    }
    return 0;
}
int bipartite(int n,int bound){
    
    if(visited2[n] == 1){
        return 0;
    }
    visited2[n] = 1;
    
    for(int i = 0; i<car2[n].size(); i++){
        if(car2[n][i].dist > bound)
            continue;
        
        if(ans[car2[n][i].r][car2[n][i].c].dist == -1){
            ans[car2[n][i].r][car2[n][i].c] = car2[n][i];
            //return car2[n][i].dist;
            return 1;
        }
        else
        {
            if(bipartite(ans[car2[n][i].r][car2[n][i].c].num,bound) != 0){
                ans[car2[n][i].r][car2[n][i].c] = car2[n][i];
                //return max(car2[n][i].dist,car2[n].begin()->dist);
                return 1;
            }
        }
    }
    return 0;
}
void bfs(int q){
    while(!que.empty()){
        node n;
        int qr = que.front().r;
        int qc = que.front().c;
        int qd = que.front().dist;
        
        if(visited[qr][qc] == 1){
            que.pop();
            continue;
        }
        visited[qr][qc] = 1;

        if(board[qr][qc] == 2){
            que.pop();
            continue;
        }
        
        if(board[qr][qc] == 1){
            node n;
            n.num = q;
            n.r = qr;
            n.c = qc;
            n.dist = qd;
            //park[qr][qc].push_back(n);
            car2[q].push_back(n);
            que.pop();
        }
        
        if(qr-1>=0){
            n.r = qr-1;
            n.c = qc;
            n.dist = qd+1;
            que.push(n);
        }
        if(qr+1<r){
            n.r = qr+1;
            n.c = qc;
            n.dist = qd+1;
            que.push(n);
        }
        if(qc-1>=0){
            n.r = qr;
            n.c = qc-1;
            n.dist = qd+1;
            que.push(n);
        }
        if(qc+1<c){
            n.r = qr;
            n.c = qc+1;
            n.dist = qd+1;
            que.push(n);
        }
    }
}

int main(){
    
    int cnt = 0;
    cin>>r>>c;
    board = new int*[r];
    for(int i = 0; i<r; i++){
        board[i] = new int[c];
    }
    visited = new int*[r];
    for(int i = 0; i<r; i++){
        visited[i] = new int[c];
    }
    ans = new node*[r];
    for(int i = 0; i<r; i++){
        ans[i] = new node[c];
    }
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            ans[i][j].dist = -1;
        }
    }
    
    char input;
    
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin>>input;
            if(input == 'C'){
                board[i][j] = -1;
                node n;
                n.c = j;
                n.r = i;
                n.dist = 0;
                car.push_back(n);
                cnt++;
            }
            else if(input == 'P'){
                board[i][j] = 1;
            }
            else if(input == '.')
                board[i][j] = 0;
            else
                board[i][j] = 2;
        }
    }
    if(car.size() == 0){
        cout<<"0"<<endl;
        return 0;
    }
    visited2 = new int[car.size()];
    car2.resize(car.size());
    for(int i = 0; i<car.size(); i++){
        for(int k = 0; k<r; k++){
            for(int j = 0; j<c; j++){
                visited[k][j] = 0;
            }
        }
        
        que.push(car[i]);
        bfs(i);
    }

    int temp = 0;
    for(int i = 0; i<car.size(); i++){
        for(int k = 0; k<car.size(); k++){
            visited2[k] = 0;
        }
        temp +=bipartite(i);
    }
    if(temp!=car.size()){
        cout<<"-1"<<endl;
        return 0;
    }
    
    int lo = 0, hi = r*c;
    
    while(lo+1<hi){
        temp = 0;
        int mid = (lo+hi)/2;
        
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                ans[i][j].dist = -1;
            }
        }
        
        for(int i = 0; i<car.size(); i++){
            for(int k = 0; k<car.size(); k++){
                visited2[k] = 0;
            }
            temp += bipartite(i,mid);
        }
        
        if(temp == car.size())
            hi = mid;
        else
            lo = mid;
    }
    cout<<hi<<endl;
}
