#include<bits/stdc++.h>
using namespace std;
int N,K,L,T;
int apple[100][100] = {0};
int board[100][100] = {0};
vector<pair<int,int> > cmd;
struct body{
    int x;
    int y;
    int pos;
};
deque<body> snake;

int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int move(int x,int y,int k,int tm){
    int cur_tm = 0;
    while(cur_tm<tm){
        body temp;

        x+=dir[k][0];
        y+=dir[k][1];
        //cout<<x<<" "<<y<<" "<<k<<endl;
        if(x>N-1 || y>N-1 || x<0 || y<0){
            return -1;
        }
        if(board[x][y] == 1){
            return -1;
        }
        if(apple[x][y] == 1){
            apple[x][y] = 0;
            body temp = {x,y,k};
            snake.push_front(temp);
            board[x][y] = 1;
        }
        else{
            body temp = {x,y,k};
            snake.push_front(temp);
            board[x][y] = 1;
            board[snake.back().x][snake.back().y] = 0;
            snake.pop_back();
        }
        cur_tm++;
        T++;
    }
    return 0;
}
int main(){
    T = 0;
    cin>>N>>K;
    for(int i = 0; i<K; i++){
        int x,y;
        cin>>x>>y;
        apple[x-1][y-1] = 1;
    }  
    cin>>L;
    for(int i= 0; i<L; i++){
        int x;
        char c;
        cin>>x>>c;
        switch(c){
            case 'L':{
                cmd.push_back(make_pair(x,0));
                break;
            }
            case 'D':{
                cmd.push_back(make_pair(x,1));
                break;
            }
        }
    }
    body start = {0,0,1};
    snake.push_back(start);
    int cmd_cnt = 0;
    int ans = 0;
    while(cmd_cnt<cmd.size()){
        body cur = snake.front();
        int res = move(cur.x,cur.y,cur.pos,cmd[cmd_cnt].first-T);
        if(res == -1){
            //cout<<"wall"<<endl;
            break;
        }
        //cout<<snake.front().pos<<endl;
        if(snake.front().pos == 0){
            if(cmd[cmd_cnt].second == 0){
                snake.front().pos = 1;
            }
            else{
                snake.front().pos = 3;
            }
        }
        else if(snake.front().pos == 1){
            if(cmd[cmd_cnt].second == 0){
                snake.front().pos = 2;
            }
            else{
                snake.front().pos = 0;
            }
        }
        else if(snake.front().pos == 2){
            if(cmd[cmd_cnt].second == 0){
                snake.front().pos = 3;
            }
            else{
                snake.front().pos = 1;
            }
        }
        else{
            if(cmd[cmd_cnt].second == 0){
                snake.front().pos = 0;
            }
            else{
                snake.front().pos = 2;
            }
        }
        cmd_cnt++;
    }
    move(snake.front().x,snake.front().y,snake.front().pos,10000);
    std::cout<<T+1;
}