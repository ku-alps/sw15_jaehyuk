#include<iostream>
#include<vector>

using namespace std;

int N,M;
vector<vector<int> > work;
vector<int> assigned;
vector<int> visited;

int dfs(int idx){
    if(visited[idx] == 1){
        return 0;
    }
    visited[idx] = 1;
    for(int i = 0; i<work[idx].size(); i++){
        if(assigned[work[idx][i]] == -1){
            assigned[work[idx][i]] = idx;
            return 1;
        }
        else{
            if(dfs(assigned[work[idx][i]]) == 1){
                assigned[work[idx][i]] = idx;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    cin>>N>>M;
    work.resize(N+1);
    assigned.resize(M+1);
    visited.resize(N+1);
    fill(assigned.begin(), assigned.end(), -1);
    int K;
    for(int i = 0; i<N; i++){
        cin>>K;
        int input;
        for(int j = 0; j<K; j++){
            cin>>input;
            work[i].push_back(input);
        }
    }
    int sum = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++)
            visited[j] = 0;
        sum += dfs(i);
    }
    cout<<sum;
}