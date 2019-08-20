#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> G;
vector<vector<int>> RG;
vector<int> visited;
vector<int> stk;
vector<int> temp;
vector<vector<int>> ans;
vector<int> chkind;
vector<int> ind;
int T,N,M;
int cnt = 0;
int scccnt = 0;

void dfs(int idx){
    if(visited[idx] == 1)
        return;
    visited[idx] = 1;
    
    for(int i = 0; i<G[idx].size(); i++){
        dfs(G[idx][i]);
    }
    stk.push_back(idx);
}

int rdfs(int idx){
    if(visited[idx] == 1)
        return 0;
    
    visited[idx] = 1;
    
    chkind[idx] = scccnt;
    temp.push_back(idx);
    
    for(int i = 0; i<RG[idx].size(); i++){
        rdfs(RG[idx][i]);
    }
    return 1;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    cin>>T;
    int a = 0,b = 0;
    for(int i = 0; i<T; i++){
        cin>>N>>M;
        visited.resize(N+1);
        G.resize(N+1);
        RG.resize(N+1);
        stk.clear();
        chkind.resize(N+1);
        ind.resize(N+1);
        chkind.clear();
        ind.clear();
        
        for(int j = 0; j<N+1; j++){
            G[j].clear();
            RG[j].clear();
        }
        
        fill(visited.begin(),visited.end(),0);
        
        for(int j = 0; j<M; j++){
            cin>>a>>b;
            a--;
            b--;
            G[a].push_back(b);
            RG[b].push_back(a);
        }
        for(int j = 0; j<N; j++){
            dfs(j);
        }
/*        for(int j = 0; j<stk.size(); j++){
            cout<<stk[j]<<" ";
        }
        cout<<'\n';*/
        fill(visited.begin(),visited.end(),0);

        for(int j = (int)stk.size()-1; j>=0; j--){
            if(rdfs(stk[j]) == 1){
                scccnt++;
            }
        }

        for(int j = 0; j<N; j++){
            for(int k = 0; k<G[j].size(); k++){
                if(chkind[j] != chkind[G[j][k]])
                    ind[chkind[G[j][k]]]++;
            }
        }
        for(int j = 0; j<scccnt; j++){
            if(ind[j] == 0)
                cnt++;
        }
        cout<<cnt<<'\n';
        cnt = 0;
        scccnt = 0;
    }
}
