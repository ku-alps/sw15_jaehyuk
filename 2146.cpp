#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
int isIsl[100][100] = {0};
int visited[100][100] = {0};
deque<pair<pair<int,int>,int> >  que;
int N;
int bfs(int a,int b){
    while(!que.empty()){
        pair<int,int> idx = que.front().first;
        int x = idx.first, y = idx.second;
        int dist = que.front().second;
        que.pop_front();

        if(arr[x][y] == 1 && dist>0){//다른 '섬'일때
            isIsl[x][y] = 0; //다른 섬에 닿았을 때 현재 섬이 아니라고 표시
            while(!que.empty())
                que.pop_back();
            return dist;
        }

        if(visited[x][y] == 1)
            continue;
        visited[x][y] = 1;
        //자신 섬일땐 거리0으로 큐 앞에서부터 push
        if(x-1>=0){
            if(visited[x-1][y]==0 && arr[x-1][y]==1){
                que.push_front(make_pair(make_pair(x-1,y),dist));
                isIsl[x-1][y] = 1;
            }
        }
        if(x+1<=N-1){
            if(visited[x+1][y]==0 && arr[x+1][y]==1){
                que.push_front(make_pair(make_pair(x+1,y),dist));
                isIsl[x+1][y] = 1;
            }
        }
        if(y-1>=0){
            if(visited[x][y-1]==0 && arr[x][y-1]==1){
                que.push_front(make_pair(make_pair(x,y-1),dist));
                isIsl[x][y-1] = 1;
            }
        }
        if(y+1<=N-1){
            if(visited[x][y+1]==0 && arr[x][y+1]==1){
                que.push_front(make_pair(make_pair(x,y+1),dist));
                isIsl[x][y+1] = 1;
            }
        }
        //=====
        //바다로 떠나는 과정 : 거리값을 전달하며 큐의 '뒤'에서부터 넣기
        //(자기 섬부터 알아야함)
        if(x-1>=0)
            if(visited[x-1][y]==0 && arr[x-1][y]==0)
                que.push_back(make_pair(make_pair(x-1,y),dist+1));
            
        if(x+1<=N-1)
            if(visited[x+1][y]==0 && arr[x+1][y]==0)
                que.push_back(make_pair(make_pair(x+1,y),dist+1));
                
        if(y-1>=0)
            if(visited[x][y-1]==0 && arr[x][y-1]==0)
                que.push_back(make_pair(make_pair(x,y-1),dist+1));
              
        if(y+1<=N-1)
            if(visited[x][y+1]==0 && arr[x][y+1]==0)
                que.push_back(make_pair(make_pair(x,y+1),dist+1));
               
    }
    return 0;
}
int main(){
    cin>>N;
    int min_dist = 100000;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            cin>>arr[i][j];

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(isIsl[i][j] == 1||arr[i][j] == 0)//이미 거친 섬이거나 바다일때->탐색필요X
                continue;
            for(int m = 0; m<N; m++)
                for(int n = 0; n<N; n++)
                    visited[m][n] = 0;

            que.push_back(make_pair(make_pair(i,j),0));            
            min_dist = min(min_dist,bfs(i,j));
        }
    }
    cout<<min_dist;
}