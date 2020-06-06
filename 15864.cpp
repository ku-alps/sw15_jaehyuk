#include<iostream>
#include<limits>
#include<cstring>
using namespace std;
int N,M,H;
int line[10][31];
int ans = 12345678;

int move(){
    for(int i = 1; i<=N; i++){
        int cur_x = i;
        int j;
        for(j = 1; j<=H; j++){
            //cout<<cur_x<<endl;
            if(cur_x<=N-1&&line[cur_x][j] == 1){
                cur_x++;
            }
            else if(cur_x-1>=1&&line[cur_x-1][j] == 1){
                cur_x--;
            }
        }
        if(cur_x != i){
            return 0;
        }
    }
    return 1;
}
int sel(int idx, int cnt){
    if(cnt>3){
        return 0;
    }
    if(move() == 1){
        ans = min(ans,cnt);
        return 1;
    }
    if(cnt == 3){
        return 0;
    }
    for(int i= idx; i<N; i++){
        for(int j =1; j<=H; j++){
            if(line[i][j] == 1)continue;
            if(i-1>=1&&line[i-1][j] == 1)continue;
            if(i+1<N&&line[i+1][j] == 1)continue;
            line[i][j] = 1;
            sel(i,cnt+1);
            line[i][j] = 0;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M>>H;
    memset(line,0,sizeof(line));
    int a,b;
    for(int i= 0; i<M; i++){
        cin>>a>>b;//a번점선위치에서 b,b+1연결
        line[b][a] = 1;
     }
    
    sel(1,0);
    if(ans>3){
        cout<<"-1";
        return 0;
    }
    cout<<ans;
    return 0;
}