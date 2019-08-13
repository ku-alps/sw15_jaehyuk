#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<long long> arr;
vector<long long> tree;
vector<long long> lazy;

long long init(int node,int start,int end){
    if(start == end)
        return tree[node] = arr[start];
    else{
        return tree[node] = init(node*2,start,(start+end)/2)+init(node*2+1,(start+end)/2+1,end);
    }
}
long long sum(int node,int left,int right,int start,int end){
    
    if(lazy[node] != 0){//when ancester has val to be updated
        tree[node] += (right-left+1)*lazy[node];
        //right-left+1 : the number of leap nodes(current range)
        
        if(left != right){   //if not leap(need more propagations)
            lazy[node*2] += lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node] = 0; //init current node's lazy
    }
    
    if(left>end || start>right){
        return 0;
    }
    if(left>=start && right<=end){
        return tree[node];
    }
    
    return sum(node*2,left,(left+right)/2,start,end)+sum(node*2+1,(left+right)/2+1,right,start,end);
}
int update(int node,int left,int right,int start,int end,long long val){
    if(lazy[node] != 0){//when ancester has val to be updated
        tree[node] += (right-left+1)*lazy[node];
        //right-left+1 : the number of leap nodes(current range)
        
        if(left != right){   //if not leap(need more propagations)
            lazy[node*2] += lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node] = 0; //init current node's lazy
    }
    
    if(left>end || start>right)
        return 0;
    
    if(left>=start && right<=end){

        tree[node] += (right-left+1)*val;
        
        if(left!=right){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return 0;
    }
    update(node*2,left,(left+right)/2,start,end,val);
    update(node*2+1,(left+right)/2+1,right,start,end,val);
    
    tree[node] = tree[node*2]+tree[node*2+1];//up propagation
    return 0;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n,m,k;
    cin>>n>>m>>k;
    int input;
    int height = (int)ceil(log2(n));
    int tree_size = pow(2,(height+1));
    tree.resize(tree_size+1);
    arr.resize(tree_size+1);
    lazy.resize(tree_size+1);
    
    fill(arr.begin(),arr.end(),0);
    fill(lazy.begin(),lazy.end(),0);
    
    for(int i = 0; i<n; i++){
        cin>>input;
        arr[i] = input;
    }
    
    init(1,0,n-1);
  
    int a,b,c;
    long long d;
    for(int i = 0; i<m+k; i++){
        cin>>a>>b>>c;
        if(a == 1){//update func
            cin>>d;
            update(1, 0, n-1, b-1, c-1, d);
            
        }
        else{//sum func
            cout<<sum(1, 0, n-1, b-1, c-1)<<'\n';
        }
    }
}
