//N-Queen
#include<iostream>
#include<cmath>

using namespace std;
int n;
int cnt = 0;
void nQueen(int** board,int x,int y){
    
    //n번 확인(x 한줄)
    for(int k = 0; k<n; k++){
        int flag = 0;
        int q = 0;
    
        for(int i = 0; i<n; i++){
            if(board[x+k][i] == 1){
                flag = 1;
                break;
            }
        }
        
        while((y + q <n && x+k+q <n)&& flag == 0){
            if(board[x+k+q][y+q] == 1){
                flag = 1;
                break;
            }
            q++;
        }
        q = 0;
        while((y - q >= 0 && x+k-q >=0)&& flag == 0){
            if(board[x+k-q][y-q] == 1){
                flag = 1;
                break;
            }
            q++;
        }
        
        q = 0;
        while((y + q <n && x+k-q >=0)&&flag == 0){
            
            if(board[x+k-q][y+q] == 1){
                flag = 1;
                break;
            }
            q++;
        }
        
        q = 0;
        while((y - q >= 0 && x+k+q <n)&&flag == 0){
            if(board[x+k+q][y-q] == 1){
                flag = 1;
                break;
            }
            q++;
        }
        
        if(flag == 1){
            continue;
        }
        if(flag == 0){
            //모든 반복문 통과 시 해당 x,y에 놓을 수 있다.
            board[k][y] = 1;
            if(y == n-1){
                cnt++;
                board[k][y]=0;
                return;
            }
        }
        nQueen(board,0,y+1);
        board[k][y] = 0;
    }
}

int main(){

    cin>>n;
    int** board = new int*[n];
    for(int i = 0; i<n;i++){
        board[i] = new int[n];
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            board[i][j] = 0;
        }
    }

    nQueen(board,0,0);
    
    cout<<cnt<<endl;
}
