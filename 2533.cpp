#include<iostream>
#include<vector>

using namespace std;

int N;
vector<vector<int> > node;

int main(){
    cin>>N;
    node.resize(N);
    int a,b;
    for(int i = 0; i<N; i++){
        cin>>a>>b;
        node[a-1].push_back(b-1);
    }
    //dfs
    
}