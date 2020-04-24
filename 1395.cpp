#include<iostream>
#include<vector>

using namespace std;

vector<int> tree;
vector<int> lazy;
vector<int> arr;

int sum(int node,int left,int right,int start,int end){
    if(lazy[node]%2 == 1)
    {
        tree[node] = (right-left+1)-tree[node];
        
        if(left != right)
        {
            if(lazy[node*2] == 0)
                lazy[node*2] = 1;
            else
                lazy[node*2] = 0;
            if(lazy[node*2+1] == 0)
                lazy[node*2+1] = 1;
            else
                lazy[node*2+1] = 0;
        }
        lazy[node] = 0;
    }
    
    if(left>end || right<start)
        return 0;
    
    if(start<=left && right<=end)
        return tree[node];
    
    return sum(node*2,left,(left+right)/2,start,end) + sum(node*2+1,(left+right)/2+1,right,start,end);
}
void update(int node,int left,int right,int start,int end){
    if(lazy[node]%2 == 1)//opposite
    {
        tree[node] = (right-left+1) - tree[node];
        if(left != right)
        {
            if(lazy[node*2] == 0)
                lazy[node*2] = 1;
            else
                lazy[node*2] = 0;
            if(lazy[node*2+1] == 0)
                lazy[node*2+1] = 1;
            else
                lazy[node*2+1] = 0;
        }
        lazy[node] = 0;
    }
    
    if(left>end || right<start)
        return;
    
    if(start<=left && right<=end)
    {
        tree[node] = (right-left+1) - tree[node];
        
        if(left != right)
        {
            if(lazy[node*2] == 0)
                lazy[node*2] = 1;
            else
                lazy[node*2] = 0;
            if(lazy[node*2+1] == 0)
                lazy[node*2+1] = 1;
            else
                lazy[node*2+1] = 0;
        }
        return;
    }
    
    update(node*2, left, (left+right)/2, start, end);
    update(node*2+1,(left+right)/2+1,right,start,end);
    
    tree[node] = tree[node*2]+tree[node*2+1];
    return;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    int o,s,t;
    lazy.resize(400001);
    arr.resize(100001);
    tree.resize(400001);
    fill(lazy.begin(),lazy.end(),0);
    fill(tree.begin(),tree.end(),0);
    
    
    for(int i = 0; i<m; i++){
        cin>>o>>s>>t;
        if(o == 1){
            cout<<sum(1, 0, n-1, s-1, t-1)<<'\n';
        }
        else{
            update(1, 0, n-1, s-1, t-1);
        }
    }
}
