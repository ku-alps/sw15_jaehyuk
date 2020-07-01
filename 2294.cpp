#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    vector<int> coin(N+1);
    vector<long long> cases(K+1,0);
    vector<long long> mcoin(100001,100001);
    for(int i = 1; i<N+1; i++)
        cin>>coin[i];
    sort(coin.begin(),coin.end());
    for(int i = 1; i<N+1; i++){
        mcoin[coin[i]] = 1;
    }
    for(int i = 1; i<N+1; i++){
        for(int j = coin[i]; j<K+1; j++){
            mcoin[j] = min(mcoin[j],mcoin[j-coin[i]]+1);
        }
    }
    if(mcoin[K] == 100001)
        mcoin[K] = -1;
    cout<<mcoin[K];
}