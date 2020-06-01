#include<bits/stdc++.h>
#include<limits>
using namespace std;
int board[51][51];
int cboard[51][51];
int visited[51][51]={0};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

vector<pair<int,int> > virus;
int N,M;
int assign = 0;
bool isComplete(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(board[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}
int main(){
    cin>>N>>M;
    int _min = INT_MAX;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];   
            cboard[i][j] = board[i][j];
            if(board[i][j] == 2){
                virus.push_back(make_pair(i,j));
            }
            if(board[i][j] == 0){
                assign++;
            }
        }
    }
    vector<int> temp;
    temp.resize(virus.size());
    fill(temp.begin(),temp.end(),0);
    for(int i = 0; i<M; i++){
        temp[virus.size()-1-i] = 1;
    }
    sort(temp.begin(),temp.end());
    do{
        for(int i= 0; i<N; i++){
            for(int j = 0; j<N; j++){
                visited[i][j] = 0;
                board[i][j] = cboard[i][j];
            }
        }
        queue<pair<int, pair<int,int> > > que;  //바이러스의 4방향 확인
        queue<pair<int,pair<int, int> > > sub_que;  //바이러스가 한번 퍼지고 난 뒤 기준이 될 바이러스 임시 저장
        for(int i = 0; i<virus.size(); i++){
            if(temp[i] == 1){
                que.push(make_pair(0,make_pair(virus[i].first,virus[i].second)));
            }
        }
        //BFS
        int cnt = 0;
        int zero_cnt = 0;
        while(true){
            
            while(!que.empty()){
                pair<int,pair<int,int> > idx = que.front();
                que.pop();
                int r = idx.second.first;
                int c = idx.second.second;
                
                int dist = idx.first;
                
                //cout<<r<<","<<c<<","<<dist<<endl;
                if(visited[r][c] == 1){
                    continue;
                }
                visited[r][c] = 1;
                if(board[r][c] == 0){
                    board[r][c] = 2;
                    zero_cnt++;
                }
                for(int i = 0; i<4; i++){
                    int x = r + dir[i][0];
                    int y = c + dir[i][1];
                    if(x>N-1 || y>N-1 || x<0 || y<0){
                        continue;
                    }
                    if(board[x][y] != 1 && visited[x][y] == 0){  
                        sub_que.push(make_pair(dist+1,make_pair(x,y)));
                    }
                    if(board[x][y] == 0 && visited[x][y] == 0){  
                        sub_que.push(make_pair(dist+1,make_pair(x,y)));  
                    }
                }
            }
            while(!sub_que.empty()){
                pair<int, pair<int,int> > idx = sub_que.front();
                sub_que.pop();
                int r = idx.second.first;
                int c = idx.second.second;
                int dist = idx.first;
                que.push(make_pair(dist,make_pair(r,c)));
            }
            if(zero_cnt == assign){
                _min = min(_min,cnt);
                break;
            }
            else{
                if(que.empty()){
                    break;
                }
            }
            cnt++;
        }
    }while(next_permutation(temp.begin(),temp.end()));

    if(_min == INT_MAX){
        cout<<"-1";
    }
    else{
        cout<<_min;
    }
}