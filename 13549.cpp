#include<bits/stdc++.h>

using namespace std;
int N,K;
vector<int> dp;
deque<int> que;

int main(){
    cin>>N>>K;

    dp.resize(100001);
    fill(dp.begin(),dp.end(),1000000);
    dp[N] = 0;
    que.push_back(N);
    int dist = 0;
    while(!que.empty()){
        //cout<<"?"<<endl;
        int idx = que.front();
        int dist = dp[idx]+1;
        que.pop_front();

        if(idx*2 <= 100000){
            if(dp[idx*2] > dist-1){
                dp[idx*2] = dist-1;
                que.push_front(idx*2);
            }
            if(idx*2 == K){
                cout<<dp[idx*2]<<'\n';
                return 0;
            }
        }

        if(idx+1 <= 100000){
            if(dp[idx+1] > dist){
                dp[idx+1] = dist;
                que.push_back(idx+1);
            }
            if(idx+1 == K){
                cout<<dp[idx+1]<<'\n';
                return 0;
            }
        }
        if(idx-1 >= 0){
            if(dp[idx-1] > dist){
                dp[idx-1] = dist;
                que.push_back(idx-1);
            }
            if(idx-1 == K){
                cout<<dp[idx-1]<<'\n';
                return 0;
            }
        }
        
    }
    cout<<dp[K]<<endl;
}