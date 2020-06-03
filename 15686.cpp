#include<bits/stdc++.h>
#include<limits>
using namespace std;
int N,M;
vector<vector<int> > board;
vector<pair<int,int> > store;
vector<pair<int,int> > house;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int calc(){
    int sum = 0;
    for(int i = 0; i<house.size(); i++){
        //int temp = bfs(house[i]);
        int temp = INT_MAX;
        for(int j = 0; j<store.size(); j++){
            if(board[store[j].first][store[j].second] == 2){
                temp = min(temp,abs(house[i].first-store[j].first)
                +abs(house[i].second-store[j].second));
            }
        }
        sum+=temp;        
    }
    return sum;
}
int main(){
    cin>>N>>M;
    board.resize(N,vector<int>(N));
    for(int i = 0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>board[i][j];
            if(board[i][j] == 2){
                store.push_back(make_pair(i,j));
            }
            if(board[i][j] == 1){
                house.push_back(make_pair(i,j));
            }
        }
    }
    vector<int> temp(M,0);
    for(int i = 0; i<store.size()-M; i++){
        temp.push_back(1);
    }
    int _min = INT_MAX;
    sort(temp.begin(),temp.end());
    do{
        auto bak = board;
        for(int i = 0; i<temp.size(); i++){
            if(temp[i] == 1){
                pair<int,int> cur = store[i];
                board[cur.first][cur.second] = 0;
            }
        }
        _min = min(_min,calc());
        board = bak;
    }while(next_permutation(temp.begin(),temp.end()));//1716
    cout<<_min;
}
