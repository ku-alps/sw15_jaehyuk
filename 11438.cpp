//using DP

#include<iostream>
#include<vector>
#include<cmath>

int maxn = 100001;
int height = log2(maxn);
using namespace std;

vector<vector<int>> arr;
vector<int> depth;
vector<vector<int>> dp;
int n,m;

void makeTree(int cur, int par){
    depth[cur] = depth[par]+1;
    dp[cur][0] = par;
    
    for(int i= 0; i<height; i++){
        dp[cur][i+1] = dp[dp[cur][i]][i];
        //2^i 번째 조상은 조상의 조상 ㅇㅅㅇ
    }
    
    for(int i = 0; i<arr[cur].size(); i++){
        int child = arr[cur][i];
        if(child != par){
            makeTree(child,cur);
        }
    }
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n;
    
    arr.resize(maxn+1);//1부터 시작
    depth.resize(maxn+1);
    dp.resize(maxn+1);
    for(int i= 0; i<maxn+1; i++)
        dp[i].resize(height+1);
    
    int a,b;
    for(int i = 0; i<n-1; i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    depth[0] = -1;//arr[1]의 depth = 0
    makeTree(1,0);//현재, 부모
    /*
    for(int i = 0; i<n; i++){
        cout<<dp[i][0]<<" ";
    }
    cout<<endl;
    */
    cin>>m;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        if(depth[a] != depth[b]){
            if(depth[a]>depth[b])
                swap(a,b);
            //b(더 깊은 것)를 쓸거기때문에
        }
        for(int j = height; j>=0; j--){
            if(depth[a]<=depth[dp[b][j]])
                b = dp[b][j];
            //b가 올라감
        }
        int lca  =a;
        
        if(a!=b){
            for(int j = height; j>=0; j--){
                if(dp[a][j] != dp[b][j]){
                    a = dp[a][j];
                    b = dp[b][j];
                }
                lca = dp[a][j];
            }
            
        }
        cout<<lca<<'\n';
    }
}
