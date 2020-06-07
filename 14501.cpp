#include<iostream>
#include<algorithm>
using namespace std;
int N;
pair<int,int> work[15];
int ans = 0;
int func(int idx,int cnt){
    if(idx==N){
        ans = max(ans,cnt);
        return 0;
    }
    if(idx+work[idx].first<=N)
        func(idx+work[idx].first,cnt+work[idx].second);
    
    
    if(idx+1<=N)
        func(idx+1,cnt);
    return 0;
}
int main(){
    cin>>N;
    for(int i = 0; i<N; i++)
        cin>>work[i].first>>work[i].second;
    func(0,0);
    cout<<ans;
}