#include<bits/stdc++.h>

using namespace std;
int N,M;
char board[11][11];
int visited[11][11][11][11] = {0};
struct status{
    int rx,ry,bx,by,hx,hy,dist;
};
queue<status> que;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

struct status move(status st,int k){    
    int rx = st.rx;
    int ry = st.ry;
    int bx = st.bx;
    int by = st.by;
    int hx = st.hx;
    int hy = st.hy;
    status nst = st;
    
    while(true){
        rx+=dir[k][0];
        ry+=dir[k][1];
        if(board[rx][ry] == '#'){
            rx -=dir[k][0];
            ry -=dir[k][1];
            break;
        }
        if(board[rx][ry] == 'O'){
            break;
        }
    }

    while(true){
        
        bx+=dir[k][0];
        by+=dir[k][1];
        if(board[bx][by] == '#'){
            bx -=dir[k][0];
            by -=dir[k][1];
            break;
        }
        if(board[bx][by] == 'O'){
            break;
        }
    }
    nst.rx = rx;
    nst.ry = ry;
    nst.bx = bx;
    nst.by = by;
    return nst;
}

int main(){
    cin>>N>>M;
    int rx,ry,bx,by,hx,hy;
    for(int i= 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
            if(board[i][j] == 'R'){
                rx = i;
                ry = j;
            }
            if(board[i][j] == 'B'){
                bx = i;
                by = j;
            }
            if(board[i][j] == 'O'){
                hx = i;
                hy = j;
            }
        }
    }
    status st = {rx,ry,bx,by,hx,hy,0};
    que.push(st);
    
    while(!que.empty()){
        status cur = que.front();
        que.pop();
        if(cur.dist > 10){
            cout<<"-1";
            return 0;
        }
        if(visited[cur.rx][cur.ry][cur.bx][cur.by] == 1)
            continue;
        visited[cur.rx][cur.ry][cur.bx][cur.by] =1;
        if(cur.rx == cur.hx && cur.ry == cur.hy){
            cout<<cur.dist<<'\n';
            return 0;
        }
        for(int i = 0; i<4; i++){
            status next = move(cur,i);  
            
            if(next.bx == next.hx && next.by == next.hy)
                continue;
            
            if(next.bx == next.rx && next.by == next.ry){
                switch(i){
                    case 0:{//1,0
                        if(cur.bx>cur.rx) next.rx--;
                        else next.bx--;
                        break;
                    }
                    case 1:{//0,1
                        if(cur.by>cur.ry) next.ry--;
                        else next.by--;
                        break;
                    }
                    case 2:{//-1,0
                        if(cur.bx>cur.rx) next.bx++;
                        else next.rx++;
                        break;
                    }
                    case 3:{//0.-1
                        if(cur.by>cur.ry) next.by++;
                        else next.ry++;
                        break;
                    }
                }
            }
            next.dist+=1;
            que.push(next);
        }
    }
    cout<<"-1"<<endl;
    return 0;
}