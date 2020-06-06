#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int board[101][101];

int r,c,k;
int x=3,y=3;
int chk(){
    if(board[r-1][c-1] == k)
        return 1;
    return 0;
}
int func(){
    if(x>=y){
        vector<int> temp;
        vector<pair<int,int> > num;
        int lmax = 0;
        for(int i = 0; i<x; i++){
            num.clear();
            num.resize(101);
            for(int j = 0; j<y; j++){
                if(board[i][j] == 0)continue;
                num[board[i][j]].first++;
                num[board[i][j]].second = board[i][j];
            }
            sort(num.begin(),num.end());
            int k = 0;
            while(num[k].first == 0){
                k++;
            }
            int l = 0;
            int tempmax = 0;
            while(k<num.size()&&l<99){
                board[i][l] = num[k].second;
                board[i][l+1] = num[k].first;
                l+=2;
                k++;
                tempmax+=2;
            }
            while(l<100){
                board[i][l] = 0;
                l++;
            }
            lmax = max(tempmax,lmax);
        }
        return y=lmax;
    }
    else{
        //C
        vector<int> temp;
        vector<pair<int,int> > num;
        int lmax = 0;
        for(int i = 0; i<y; i++){
            num.clear();
            num.resize(101);
            for(int j = 0; j<x; j++){
                if(board[j][i] == 0)continue;
                num[board[j][i]].first++;
                num[board[j][i]].second = board[j][i];
            }
            sort(num.begin(),num.end());
            int k = 0;
            while(num[k].first == 0){
                k++;
            }
            int l = 0;
            int tempmax = 0;
            while(k<num.size()&&l<99){
                board[l][i] = num[k].second;
                board[l+1][i] = num[k].first;
                l+=2;
                k++;
                tempmax+=2;
            }
            while(l<100){
                board[l][i] = 0;
                l++;
            }
            lmax = max(tempmax,lmax);
        }
        return x=lmax;
    }
}
int main(){
    memset(board,0,sizeof(board));
    cin>>r>>c>>k;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cin>>board[i][j];
        }
    }
    int ans = 0;
    while(ans<=100){
        if(chk()==1){
            cout<<ans;
            return 0;
        }
        func();
        ans++;
    }
    cout<<"-1";
    return 0;
}  