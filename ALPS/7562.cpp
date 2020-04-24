#include<iostream>
#include<cmath>
using namespace std;
short board[5][5] = {0};
int main(){
    short t;
    cin>>t;
    short targetx;short targety;
    short currentx;short currenty;
    short boardsize;
    short move=0;short x,y;
    board[0][0] = 0;
    board[1][1] = 2;
    board[2][0] = 2;
    board[0][2] = 2;
    board[2][1] = 1;
    board[1][2] = 1;
    board[1][0] = 3;
    board[0][1] = 3;
    board[2][2] = 4;
    board[3][0] = 3;
    board[3][1] = 2;
    board[3][2] = 3;
    board[3][3] = 2;
    board[2][3] = 3;
    board[1][3] = 2;
    board[0][3] = 3;
    board[4][0] = 2;
    board[4][1] = 3;
    board[4][2] = 2;
    board[4][3] = 3;
    board[3][4] = 3;
    board[2][4] = 2;
    board[1][4] = 3;
    board[0][4] = 2;
    
    for(int i = 0 ;i<t;i++){
        move = 0;
        cin>>boardsize;
        cin>>currentx>>currenty;
        cin>>targetx>>targety;
        x = abs(targetx-currentx);
        y = abs(targety-currenty);
        
        if(x==0&&y==0){
            cout<<0<<'\n';
            continue;
        }
        if(abs(targety-currenty) == 1 && abs(targetx-currentx)==1){
            if((targety == 0 &&targetx == 0)&&
               (currentx == 1&&currenty == 1)){
                cout<<4<<'\n';
                continue;
            }
            else if((targety == 1 &&targetx == 1)&&
                    (currentx == 0&&currenty == 0)){
                cout<<4<<'\n';
                continue;
            }
            
            else if((targety == boardsize-1 &&targetx == 0)&&(currentx == 1&&currenty == boardsize-2)){
                cout<<4<<'\n';
                continue;
            }
            else if((targety == boardsize-2 &&targetx == 1)&&(currentx == 0&&currenty == boardsize-1)){
                cout<<4<<'\n';
                continue;
            }
            
            else if((targety == boardsize-1 &&targetx == boardsize-1)&&(currentx == boardsize-2&&currenty == boardsize-2)){
                cout<<4<<'\n';
                continue;
            }
            else if((targety == boardsize-2 &&targetx == boardsize-2)&&(currentx == boardsize-1&&currenty == boardsize-1)){
                cout<<4<<'\n';
                continue;
            }
            else if((targety == 0 &&targetx == boardsize-1)&&(currentx == boardsize-2&&currenty == 1)){
                cout<<4<<'\n';
                continue;
            }
            else if((targety == 1 &&targetx == boardsize-2)&&(currentx == boardsize-1&&currenty == 0)){
                cout<<4<<'\n';
                continue;
            }

        }
        if(boardsize == 4&&((x== 3&&y==0)||(x==0&&y==3)))
        {
            cout<<5<<'\n';
            continue;
        }
           
        int count = 0;
        
        while(!(x<=4&&y<=4)){
            count++;
            if(x>y){
                x = abs(x-2);
                y = abs(y-1);
                move++;
            }
            else{
                y = abs(y-2);
                x = abs(x-1);
                move++;
            }
        }
        if(x==4&&y==4)
            cout<<move+4<<'\n';
        else
            cout<<move+board[x][y]<<'\n';
    }
}
