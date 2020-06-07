#include <iostream>
using namespace std;
int board[101][101]={0,};
int N;
int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
//처음부터 그리기
pair<int,int> makeCurve(int x,int y,int d, int g){
    int r = x+dir[d][0];
    int c = y+dir[d][1];
    if(g == 0){
        board[r][c] = 1;
        board[x][y] = 1;
        return make_pair(r,c);
    }
    pair<int,int> ep = makeCurve(x,y,d,g-1);
    //cout<<"g: "<<g<<" ep : "<<ep.first<<" "<<ep.second<<endl;
    int rx = (x-ep.first)*0+(y-ep.second)*(1) + ep.first;
    int ry = (x-ep.first)*(-1)+(y-ep.second)*0 + ep.second;
    pair<int,int> eep = makeCurve(rx,ry,(d+3)%4,g-1);
    //cout<<"g: "<<g<<" eep : "<<eep.first<<" "<<eep.second<<endl;
    return eep;
}
int main(){
    cin>>N;
    int x,y,d,g;
    for(int i = 0; i<N; i++){
        cin>>x>>y>>d>>g;
        int k = 0;
        makeCurve(x,y,d,g);
    }
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    int ans = 0;
    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            if(board[i][j] == 1 && board[i][j+1] == 1){
                ans++;
            }
        }
    }
    cout<<ans;
}