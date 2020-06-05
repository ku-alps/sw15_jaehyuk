#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> inorder;
vector<int> visited;
vector<int> postorder;
vector<vector<int> > tree;
vector<int> seq;
vector<int> stk;

//post의 루트 -> in에서 좌우 트리로 나누기
int idx=0;
int k = 0;
int makeTree(int start,int end){
    /*if(postorder.empty()){
        return -1;
    }*/
    if(start >= end){
        return inorder[start]-1;
    }

    idx = stk.back();
    stk.pop_back();
    int node = seq[k];
    cout<<"k :"<<k;
    k--;
    cout<<" idx: "<<idx-1<<" node : "<<node<<endl;
    
    //cout<<inorder[node]<<endl;
    //cout<<node<<endl;
    tree[idx-1][0] = makeTree(start,node-1);
    tree[idx-1][1] = makeTree(node+1,end);
    
    return inorder[node]-1;
}

int main(){
    cin>>N;
    k = N-1;
    inorder.resize(N);
    postorder.resize(N);
    stk.resize(N);
    seq.resize(N);
    visited.resize(N);
    fill(visited.begin(),visited.end(),0);
    tree.resize(N);
    for(int i = 0; i<N; i++){
        tree[i].resize(2);
        fill(tree[i].begin(),tree[i].end(),-1);
    }
    for(int i = 0; i<N; i++)
        cin>>inorder[i];
    for(int i = 0; i<N; i++){
        cin>>postorder[i];
        stk[i] = postorder[i];
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(postorder[i] == inorder[j]){
                seq[i] = j;
                break;
            }
        }
    }

    for(int i = 0; i<N; i++){
        cout<<postorder[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i<N; i++){
        cout<<seq[i]<<" ";
    }
    cout<<endl;
/*
    for(int i = 0; i<N; i++){
        cout<<seq[i]<<" ";
    }
    cout<<endl<<endl;
*/
    makeTree(0,N-1);
    
    /*
    int root = postorder[N-1]-1;
    cout<<0<<" "<<N-1<<" "<<root<<endl;
    */
    for(int i = 0; i<N; i++){
        for(int j = 0; j<tree[i].size(); j++){
            cout<<tree[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"?"<<endl;
}