#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    vector<int> coin(N+1);
    vector<long long> cases(K+1,0);
    for(int i = 1; i<N+1; i++)
        cin>>coin[i];
    sort(coin.begin(),coin.end());
    cases[coin[0]] = 1;
    for(int i = 1; i<N+1; i++)
        for(int j = coin[i]; j<K+1; j++)   
            cases[j] += cases[j-(coin[i])];
    cout<<cases[K];
}