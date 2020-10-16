#include<iostream>
#include<queue>
using namespace std;
struct node{
    int x;
    int y;
    int dist;
};
int arr[51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int ddx[7][4] = {{-1,0,1,0},{-1,1,0,0},{0,0,0,0},{-1,0,0,0},{1,0,0,0},{0,1,0,0},{-1,0,0,0}};
int ddy[7][4] = {{0,1,0,-1},{0,0,0,0},{-1,1,0,0},{0,1,0,0},{0,1,0,0},{-1,0,0,0},{0,-1,0,0}};
int main(){
    int T;
    cin>>T;
    for(int k = 1; k<=T; k++){
        int n,m,r,c,l;
        cin>>n>>m>>r>>c>>l;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>arr[i][j];
            }
        }
        //BFS
        queue<node> que;
        node start;
        start.x = r;
        start.y = c;
        start.dist = 1;
        que.push(start);
        int island[51][51] = {0,};
        int visited[51][51] = {0,};
        while(!que.empty()){
            node idx = que.front();
            int x = idx.x;
            int y = idx.y;
            int dist = idx.dist;
            que.pop();
            //cout<<x<<y<<endl;
            if(visited[x][y] == 1){
                continue;
            }
            visited[x][y] = 1;
            if(dist == l+1){
                break;
            }
            if(arr[x][y] >= 1){
                island[x][y] = 1;
            }
            for(int i = 0; i<4; i++){
                int xx = x+ddx[arr[x][y]-1][i];
                int yy = y+ddy[arr[x][y]-1][i];
                if(xx>=0 && xx<n && yy>=0 && yy<m){
                    if(visited[xx][yy]==0 && arr[xx][yy] >= 1){
                        for(int j = 0; j<4; j++){
                            int xxx = xx+ddx[arr[xx][yy]-1][j];
                            int yyy = yy+ddy[arr[xx][yy]-1][j];
                            if(xxx==x&&yyy==y){
                                node temp;
                                temp.x = xx;
                                temp.y = yy;
                                temp.dist = dist+1;
                                que.push(temp);
                            }
                        }
                    }
                }
            }
        }
        int sum = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                //cout<<island[i][j]<<" ";
                sum+=island[i][j];
            }
            //cout<<endl;
        }
        cout<<"#"<<k<<" "<<sum<<'\n';
    }
}
