#include<iostream>
#include<vector>

using namespace std;

vector<int> book;
vector<int> visited;
vector<vector<int>> match;

int visitCnt;
int bipartite(int idx){
    if(visited[idx] == 1)
        return 0;
   
    visited[idx] = 1;
    
    if(match[idx].size() == 0)
        return 0;
    
    for(int i = match[idx].front(); i<=match[idx].back(); i++){
        if(book[i] == -1){
            book[i] = idx;
            return 1;
        }
        else{
            if(bipartite(book[i]) == 1){
                book[i] = idx;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    book.resize(1001);
    int t;
    int m,n;
    cin>>t;
    match.resize(1001);
    visited.resize(1001);
    
    for(int i = 0; i<t; i++){
        cin>>n>>m;
        int ans = 0;
        visitCnt = 0;
        /*
        for(int j = 0; j<m; j++){
            match[j].clear();
        }
         */
        fill(book.begin(),book.end(),-1);
        
        for(int j = 0; j<m; j++){
            int a,b;
            cin>>a>>b;
            match[j].clear();
            match[j].push_back(a-1);
            match[j].push_back(b-1);
        }
        for(int k = 0; k<m; k++){
            fill(visited.begin(),visited.end(),0);
            ans += bipartite(k);
        }
        cout<<ans<<endl;
    }
}
