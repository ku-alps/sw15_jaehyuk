#include<iostream>
#include<vector>
using namespace std;

int main(){
    int T,N,M;
    
    cin>>T;
    while(T--){
        cin>>N>>M;
        vector<vector<int> > board;
        board.resize(N);
        for(int i = 0; i<N; i++)
            board[i].resize(N);
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                cin>>board[i][j];
            }
        }
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                if(board[i][j] != 0){
                    if(i+1<N&&j+1<M){
                        if(
                        board[i+1][j]!=0&&
                        board[i][j+1]!=0&&
                        board[i+1][j+1]!=0
                        ){
                            board[i][j] = 2;
                            board[i+1][j]=2;
                            board[i][j+1]=2;
                            board[i+1][j+1]=2;
                        }
                    }
                }
            }
        }
        bool ans = true;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(board[i][j] == 1){
                    ans = false;
                }
            }
        }
        if(ans)
            cout<<"YES"<<'\n';
        else
          	cout<<"NO"<<'\n';
    }
}
