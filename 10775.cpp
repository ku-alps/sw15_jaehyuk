#include<iostream>
#include<vector>

using namespace std;
int G,P;
vector<int> gate;
vector<int> used;
int cnt = 0;

int find(int idx){
    if(gate[idx]<0)
        return idx;
    gate[idx] = find(gate[idx]);
    return gate[idx];
}
void merge(int a,int b)
{
    a = find(a);
    b = find(b);
    
    if(a == b)
        return;
    gate[a] += gate[b]; //앞의 인자에 합치기
    gate[b] = a;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>G>>P;
    gate.resize(G);
    used.resize(G);
    fill(gate.begin(),gate.end(),-1);
    fill(used.begin(),used.end(),0);
    int gn;
    for(int i = 0;i<P; i++){
        cin>>gn;
        gn-=1;
        
        if(used[gn] == 0){
            used[gn] = 1;
            cnt++;
            if(gn != 0){
                merge(gn-1,gn);
            }
        }
        else if(used[find(gn)] == 0){
            used[find(gn)] = 1;
            cnt++;
            if(find(gn) != 0)
                merge(find(gn)-1,find(gn));
        }
        else
            break;
    }
    cout<<cnt<<'\n';
}
