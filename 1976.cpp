#include<iostream>
#define INF 200000000
using namespace std;
int N,M;
int** adj;
int* path;
int* node;

int find(int idx)
{
    if(node[idx]<0)
        return idx;
    node[idx] = find(node[idx]);
    return node[idx];
}
void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    
    if(node[a] < node[b])
        //a가 속한 집합의 크기가 b의 집합보다 크거나 같을 때-> b가 a로 병합됨
    {
        node[a] += node[b];
        node[b] = a;
    }
    else
    {
        node[b] += node[a];
        node[a] = b;
    }
}
bool chk(int a,int b){
    a = find(a);
    b = find(b);
    if(a ==b)
        return true;
    else
        return false;
}
int main(){
    cin>>N>>M;
    path = new int[M];
    node = new int[N];
    fill(node,node+N,-1);

    int input;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>input;
            if(input == 1)
                merge(i,j);
        }
    }
    
    for(int i = 0; i<M; i++){
        cin>>path[i];
    }
    for(int i = 1; i<M; i++){
        if(!chk(path[i-1]-1,path[i]-1)){
            cout<<"NO"<<'\n';
            return 0;
        }
    }
    cout<<"YES"<<'\n';
}