#include<bits/stdc++.h>

using namespace std;
int N;
vector<vector<int> > arr;
int cases = 0;
int dfs(int x,int y, int kind){
    if(x == N-1 && y==N-1){
        cases++;
        return 0;
    }
    if(kind == 0){
        
        if(y+1<=N-1 && arr[x][y+1] == 0){
            dfs(x,y+1,0);
        }
        if((x+1<=N-1&&y+1<=N-1)&&arr[x+1][y+1] == 0){
            if(arr[x+1][y]==0 && arr[x][y+1] == 0)
                dfs(x+1,y+1,1);
        }
    }
    else if(kind == 1){
        if((x+1<=N-1&&y+1<=N-1)&&arr[x+1][y+1] == 0){
            if(arr[x+1][y]==0 && arr[x][y+1] == 0)
                dfs(x+1,y+1,1);
        }
        if(y+1<=N-1 && arr[x][y+1] == 0){
            dfs(x,y+1,0);
        }
        if(x+1<=N-1 && arr[x+1][y] == 0){
            dfs(x+1,y,2);
        }
    }
    else{
        if(x+1<=N-1 && arr[x+1][y] == 0){
            dfs(x+1,y,2);
        }
        if((x+1<=N-1&&y+1<=N-1)&&arr[x+1][y+1] == 0){
            if(arr[x+1][y]==0 && arr[x][y+1] == 0)
                dfs(x+1,y+1,1);
        }
    }
    return 0;
}

int main(){
    //Brute Force

    cin>>N;
    arr.resize(N);
    for(int i = 0; i<N; i++)
        arr[i].resize(N);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    dfs(0,1,0);
    cout<<cases<<endl;
}