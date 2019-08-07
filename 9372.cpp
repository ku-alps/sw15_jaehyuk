#include<cstdio>
#include<vector>

using namespace std;
int* p;
int find(int idx)
{
    if(p[idx]<0){
        return idx;
    }
    p[idx] = find(p[idx]);
    return p[idx];
}
void merge(int a,int b){
    a = find(a);
    b = find(b);
    
    if(a == b)
        return;
    
    if(p[a]<p[b])
    {
        p[a]+=p[b];
        p[b] = a;
    }
    else{
        p[b]+= p[a];
        p[a] = b;
    }
}
int main(){
    int t;
    int n,m;
    scanf("%d",&t);
    for(int i = 0; i<t; i++){
        scanf("%d %d",&n,&m);
        
        p = new int[n];
        for(int i = 0; i<n; i++){
            p[i] = -1;
        }
        
        int a=0,b;
        for(int j = 0; j<m; j++){
            scanf("%d %d",&a,&b);
            merge(a-1,b-1);
        }
        printf("%d\n",(-1)*p[find(a-1)]-1);
    }
}
