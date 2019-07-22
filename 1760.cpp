#include<iostream>
#include<vector>

using namespace std;
int m,n;

vector<int> visited;
vector<int> put;

int bipartite(vector<vector<int>> match,int idx){
    if(visited[idx] == 1){
        return 0;
    }
    visited[idx] = 1;
    
    for(int i = 0; i<match[idx].size(); i++){
        if(put[match[idx][i]] == 0){
            put[match[idx][i]] = idx;
            return 1;
        }
        else{
            if(bipartite(match,put[match[idx][i]]) == 1){
                put[match[idx][i]] = idx;
                return 1;
            }
        }
    }
    return 0;
}


int main(){
    
    
    cin>>m>>n;
    visited.resize(10000);
    put.resize(10000);
    fill(visited.begin(),visited.end(),0);
    fill(put.begin(),put.end(),0);
    
    int** board = new int*[m];
    for(int i = 0; i<m; i++){
        board[i] = new int[n];
    }
    
    int** row = new int*[m];
    for(int i = 0; i<m; i++){
        row[i] = new int[n];
    }
  
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>board[i][j];
        }
    }
    
    
    int rcnt = 0;
    for(int i = 0; i<m; i++){
        int chk = 0;
        for(int j = 0; j<n; j++){
            if(board[i][j] == 0 || board[i][j] == 1){
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
                chk = 0;  //벽만나면 초기화
        }
    }
    vector<vector<int>> match;
    match.resize(10000);
    int ccnt = 0;
    for(int i = 0; i<n; i++){
        int chk = 0;
        for(int j = 0; j<m; j++){
            if(board[j][i] == 0 || board[j][i] == 1){
                if(chk == 0){
                    ccnt++;
                    if(board[j][i] == 0){
                        match[ccnt].push_back(row[j][i]);
                        //cout<<ccnt<<" "<<row[j][i]<<endl;
                        chk = 1;
                    }
                }
                else{
                    if(board[j][i] == 0){
                        match[ccnt].push_back(row[j][i]);
                        //cout<<ccnt<<" "<<row[j][i]<<endl;
                        chk = 1;
                    }
                }
            }
            else
                chk = 0;
        }
    }
    int ans = 0;
    //match에 대해 이분매칭
    for(int i = 1; i<=ccnt; i++){
        fill(visited.begin(),visited.end(),0);
        ans+=bipartite(match,i);
    }
    cout<<ans<<endl;
}
