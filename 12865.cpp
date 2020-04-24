#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
vector<pair<int,int> > P;
vector<vector<int> > bag;
bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.first < b.first)
        return true;
    if(a.first == b.first)
        return (a.second>b.second);
    else
        return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>K;
    
    P.resize(N);
    bag.resize(101);
    for(int i = 0; i<101; i++)
        bag[i].resize(100001);

    int W,V;
    for(int i = 0; i<N; i++){
        cin>>P[i].first>>P[i].second;
    }
    //sort(P.begin(), P.end(),cmp);
    /*
    for(int i = 0; i<N; i++){
        cout<<P[i].first<<" "<<P[i].second<<endl;
    }
    */
    for(int i = 0; i<=K; i++){
        if(i>=P[0].first)
            bag[0][i] = P[0].second;
        else
            bag[0][i] = 0;
    }
    
    for(int i = 1; i<N; i++){
        for(int j = 0; j<K+1; j++){
            if(j<P[i].first)
                bag[i][j] = bag[i-1][j];
            else{
                bag[i][j] = max(bag[i-1][j],P[i].second+bag[i-1][j-P[i].first]);
            }
        }
    }
    //sort(bag[N-1].begin(),bag[N-1].end());
    cout<<bag[N-1][K]<<endl;
    
}