#include<iostream>
#include<vector>

using namespace std;
int visited[10000];
vector<int> put;
vector<vector<int>> match;
int visitCnt;
int bipartite(int idx){
    if(visited[idx] == visitCnt){
        return 0;
    }
    visited[idx] = visitCnt;
    
    for(int i = 0; i<match[idx].size(); i++){
        if(put[match[idx][i]] == 0){
            put[match[idx][i]] = idx;
            return 1;
        }
        else{
            if(bipartite(put[match[idx][i]]) == 1){
                put[match[idx][i]] = idx;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    
    put.resize(10000);
    fill(put.begin(),put.end(),0);
    
    
    int n;
    cin>>n;
    int**board = new int*[n];
    for(int i = 0; i<n; i++){
        board[i] = new int[n];
    }
    char input;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            cin>>input;
            if(input == 'X')
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
    int** row = new int*[n];
    for(int i = 0; i<n; i++){
        row[i] = new int[n];
    }
    
    int rcnt = 0;
    for(int i = 0; i<n; i++){
        int chk = 0;
        for(int j = 0; j<n; j++){
            if(board[i][j] == 0){
                if(chk == 0){
                    rcnt++;
                    row[i][j] = rcnt;
                    chk = 1;
                }
                else{
                    row[i][j] = rcnt;
                    
                }
            }
            else
                chk = 0;  //폰만나면 초기화
        }
    }
    match.resize(10000);
    int ccnt = 0;
    for(int i = 0; i<n; i++){
        int chk = 0;
        for(int j = 0; j<n; j++){
            if(board[j][i] == 0){
                if(chk == 0){
                    ccnt++;
                    match[ccnt].push_back(row[j][i]);
                    //cout<<ccnt<<" "<<row[j][i]<<endl;
                    chk = 1;
                }
                else{
                    match[ccnt].push_back(row[j][i]);
                    //cout<<ccnt<<" "<<row[j][i]<<endl;
                    chk = 1;
                }
            }
            else
                chk = 0;
        }
    }
    
    int ans = 0;
    //match에 대해 이분매칭
    for(int i = 1; i<=ccnt; i++){
        visitCnt++;
        ans+=bipartite(i);
    }
    cout<<ans<<endl;
}
