#include<bits/stdc++.h>
using namespace std;
int N,M,x,y,K;
int board[20][20];
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};

struct dice{
    int top;
    int bottom;
    int up,down,left,right;
};
int main(){
    cin>>N>>M>>x>>y>>K;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
        }
    }
    int cmd;
    dice cur ={0,0,0,0,0,0};
    for(int i = 0; i<K; i++){
        cin>>cmd;
        x+= dir[cmd-1][0];
        y+= dir[cmd-1][1];
        if(x>N-1 || y>M-1 || x<0 || y<0){
            x-= dir[cmd-1][0];
            y-= dir[cmd-1][1];
            continue;
        }
        switch(cmd){
            case 1:{//go Right
                int temp = cur.bottom;
                cur.bottom = cur.right;
                cur.right = cur.top;
                cur.top = cur.left;
                cur.left = temp;
                break;
            }
            case 2:{//go Left
                int temp = cur.bottom;
                cur.bottom = cur.left;
                cur.left = cur.top;
                cur.top = cur.right;
                cur.right = temp;
                break;
            }
            case 3:{//go Up
                int temp = cur.bottom;
                cur.bottom = cur.up;
                cur.up = cur.top;
                cur.top = cur.down;
                cur.down = temp;
                break;
            }
            case 4:{//go Down
                int temp = cur.bottom;
                cur.bottom = cur.down;
                cur.down = cur.top;
                cur.top = cur.up;
                cur.up = temp;
                break;
            }
        }
        if(board[x][y] != 0){
            cur.bottom = board[x][y];
            board[x][y] = 0;
        }
        else{
            board[x][y] = cur.bottom;
        }
        cout<<cur.top<<'\n';
    }
}