#include<bits/stdc++.h>
using namespace std;

int N,M,T;
int board[51][51];
//뒤의 인덱스가 앞으로 가면 시계방향, 앞의 인덱스가 뒤로가면 반시계방향
void rotate(int num,int dirc, int cnt){
    
    int temp[51];
    for(int i = 0; i<M; i++){
        temp[i] = board[num][i];
    }
    if(dirc == 0){//시계방향
        int start = M-cnt;
        int endpoint = cnt;
        int k= 0;
        while(start<M){
            temp[k] = board[num][start];
            start++;
            k++;
        }
        k = 0;
        while(endpoint<=M-cnt){
            temp[endpoint] = board[num][k];
            k++;
            endpoint++;
        }
        for(int i = 0; i<M; i++){
            board[num][i] = temp[i];
        }
    }
    else{ //반시계방향
        int start = 0;
        int endpoint = start+cnt-1;
        while(start+cnt<=M-1){
            temp[start+cnt] = board[num][start];
            start++;
        }
        int k = 0;
        while(endpoint<=M-1){
            temp[k] = board[num][endpoint];
            k++;
            endpoint++;
        }
        for(int i = 0; i<M; i++){
            board[num][i] = temp[i];
        }
        
    }
}
void rotate2(int num,int dirc, int cnt){
    
    int temp[51];
    
    for(int j = 0; j<cnt; j++){
        if(dirc == 0){//시계방향
            for(int i = 0; i<M-1; i++){
                temp[i+1] = board[num][i];
            }
            temp[0] = board[num][M-1];
        }
        else{ //반시계방향
            for(int i = 1; i<=M-1; i++){
                temp[i-1] = board[num][i];
            }
            temp[M-1] = board[num][0];
        }
        for(int i = 0; i<M; i++){
            board[num][i] = temp[i];
        }
    }
    
    
}
int remove(int r,int c){
    int visited[51][51] = {0};
    vector<pair<int,int> > vec;
    queue<pair<int,int> > que;
    que.push(make_pair(r,c));
    while(!que.empty()){
        pair<int,int> idx = que.front();
        int x = idx.first;
        int y = idx.second;
        
        que.pop();
        if(visited[x][y] == 1 ){
            continue;
        }
        visited[x][y] = 1;
        if(board[x][y] == -1){
            continue;
        }
        vec.push_back(make_pair(x,y));

        if(x == 1){
            if(y == 0){
                if(visited[x][y+1] == 0&&board[x][y]==board[x][y+1]){
                    que.push(make_pair(x,y+1));
                }
                if(visited[x][M-1] == 0&&board[x][y]==board[x][M-1]){
                    que.push(make_pair(x,M-1));
                }
                if(visited[x+1][y] == 0&&board[x][y]==board[x+1][y]){
                    que.push(make_pair(x+1,y));
                }
            }
            else if(y == M-1){
                if(visited[x][0] == 0&&board[x][y]==board[x][0]){
                    que.push(make_pair(x,0));
                }
                if(visited[x][y-1] == 0&&board[x][y]==board[x][y-1]){
                    que.push(make_pair(x,y-1));
                }
                if(visited[x+1][y] == 0&&board[x][y]==board[x+1][y]){
                    que.push(make_pair(x+1,y));
                }
            }
            else{
                if(visited[x][y+1] == 0&&board[x][y]==board[x][y+1]){
                    que.push(make_pair(x,y+1));
                }
                if(visited[x][y-1] == 0&&board[x][y]==board[x][y-1]){
                    que.push(make_pair(x,y-1));
                }
                if(visited[x+1][y] == 0&&board[x][y]==board[x+1][y]){
                    que.push(make_pair(x+1,y));
                }
            }
        }
        else if(x == N){
            if(y == 0){
                if(visited[x][y+1] == 0&&board[x][y]==board[x][y+1]){
                    que.push(make_pair(x,y+1));
                }
                if(visited[x][M-1] == 0&&board[x][y]==board[x][M-1]){
                    que.push(make_pair(x,M-1));
                }
                if(visited[x-1][y] == 0&&board[x][y]==board[x-1][y]){
                    que.push(make_pair(x-1,y));
                }
            }
            else if(y == M-1){
                if(visited[x][0] == 0&&board[x][y]==board[x][0]){
                    que.push(make_pair(x,0));
                }
                if(visited[x][y-1] == 0&&board[x][y]==board[x][y-1]){
                    que.push(make_pair(x,y-1));
                }
                if(visited[x-1][y] == 0&&board[x][y]==board[x-1][y]){
                    que.push(make_pair(x-1,y));
                }
            }
            else{
                if(visited[x][y+1] == 0&&board[x][y]==board[x][y+1]){
                    que.push(make_pair(x,y+1));
                }
                if(visited[x][y-1] == 0&&board[x][y]==board[x][y-1]){
                    que.push(make_pair(x,y-1));
                }
                if(visited[x-1][y] == 0&&board[x][y]==board[x-1][y]){
                    que.push(make_pair(x-1,y));
                }
            }
        }
        else{
            if(y == 0){
                if(visited[x][y+1] == 0&&board[x][y]==board[x][y+1]){
                    que.push(make_pair(x,y+1));
                }
                if(visited[x][M-1] == 0&&board[x][y]==board[x][M-1]){
                    que.push(make_pair(x,M-1));
                }
                if(visited[x+1][y] == 0&&board[x][y]==board[x+1][y]){
                    que.push(make_pair(x+1,y));
                }
                if(visited[x-1][y] == 0&&board[x][y]==board[x-1][y]){
                    que.push(make_pair(x-1,y));
                }
            }
            else if(y == M-1){
                if(visited[x][0] == 0&&board[x][y]==board[x][0]){
                    que.push(make_pair(x,0));
                }
                if(visited[x][y-1] == 0&&board[x][y]==board[x][y-1]){
                    que.push(make_pair(x,y-1));
                }
                if(visited[x+1][y] == 0&&board[x][y]==board[x+1][y]){
                    que.push(make_pair(x+1,y));
                }
                if(visited[x-1][y] == 0&&board[x][y]==board[x-1][y]){
                    que.push(make_pair(x-1,y));
                }
            }
            else{
                if(visited[x][y+1] == 0&&board[x][y]==board[x][y+1]){
                    que.push(make_pair(x,y+1));
                }
                if(visited[x][y-1] == 0&&board[x][y]==board[x][y-1]){
                    que.push(make_pair(x,y-1));
                }
                if(visited[x+1][y] == 0&&board[x][y]==board[x+1][y]){
                    que.push(make_pair(x+1,y));
                }
                if(visited[x-1][y] == 0&&board[x][y]==board[x-1][y]){
                    que.push(make_pair(x-1,y));
                }
            }
        }
    }
    if(vec.size()>1){
        for(int i = 0; i<vec.size(); i++){
            board[vec[i].first][vec[i].second] = -1;
        }
    }
    return vec.size();
}
int mysum(){
    int sum = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j]!=-1){
                sum+=board[i][j];
            }
        }
    }
    return sum;
}
double myavg(){
    int sum = 0;
    int cnt = 0;
    double avg = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<M; j++){
            
            if(board[i][j]!=-1){
                sum+=board[i][j];
                cnt++;
            }
        }
    }
    if(cnt == 0)
        return 0;
    return (double)sum/(double)cnt;
}
void edit(double avg){
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] != -1){
                if(avg<board[i][j]){
                    board[i][j] -=1;
                }
                else if(avg>board[i][j]){
                    board[i][j] += 1;
                }
            }
        }
    }
}
int main(){
    cin>>N>>M>>T;
    int x,d,k;
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
        }
    }
    for(int t = 0; t<T; t++){
        cin>>x>>d>>k;
        int idx = 1;
        while(x*idx<=N){
            rotate2(x*idx,d,k);
            idx++;
        }
        
        int temp = 0;
        int rmcnt = 0;
        for(int i = 1; i<=N; i++){
            for(int j = 0; j<M; j++){
                temp = remove(i,j);
                if(temp > 1){
                    rmcnt = 1;
                }
            }
        }
        //cout<<"rmcnt:"<<rmcnt<<endl;
        if(rmcnt == 0){
            double avg = myavg();
            if(avg == 0){
                cout<<0<<'\n';
                return 0;
            }
            edit(avg);
        }
    }
    cout<<mysum()<<'\n';
}