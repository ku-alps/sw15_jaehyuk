//4792

#include<iostream>
#include<vector>
#include<algorithm>
//#include<queue>
#define V_MAX 1001

using namespace std;
int n,m,k;
struct edge{
    int from;
    int to;
    int weight;
    edge(){};
    edge(int a,int b,int c):from(a),to(b),weight(c){};
};
vector<edge> edg;
vector<int> p;
bool cmp_max(edge &a, edge &b){
    return a.weight > b.weight;
}
bool cmp_min(edge &a, edge &b){
    return a.weight < b.weight;
}
int find(int idx){
    if(p[idx] < 0)
        return idx;
    p[idx] = find(p[idx]);
    return p[idx];
}
int merge(int a,int b){
    a = find(a);
    b = find(b);
    
    if(a == b)
        return 0;
    
    p[a] += p[b];
    p[b] = a;
    return 1;
}
int kruskal(){
    int sum = 0;
    for(int i = 0; i<m; i++){
        int temp = merge(edg[i].from,edg[i].to);
        if(edg[i].weight == 1){
            sum += temp;
        }
    }
    return sum;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    while(true){
        cin>>n>>m>>k;
        
        if(n == 0 && m==0 &&k ==0)
            return 0;
        
        edg.clear();
        p.resize(n);
        edg.resize(m);
        fill(p.begin(),p.end(),-1);

        for(int i = 0; i<m; i++){
            int a,b;
            char c;
            cin>>c>>a>>b;
            
            if(c == 'B'){
                edge e = edge(a-1,b-1,1);
                edg[i] = e;
            }
            else if(c == 'R'){
                edge e = edge(a-1,b-1,0);
                edg[i] = e;
            }
        }
        sort(edg.begin(),edg.end(),cmp_min);//B in Rs
        int blueMin = kruskal();
        
        fill(p.begin(),p.end(),-1);
        
        sort(edg.begin(),edg.end(),cmp_max);//R in Bs
        int blueMax = kruskal();
        
        //cout<<blueMin<<" "<<blueMax<<endl;
        if(k>=blueMin&&k<=blueMax){
            printf("1\n");
        }
        else
            printf("0\n");
    }
}
