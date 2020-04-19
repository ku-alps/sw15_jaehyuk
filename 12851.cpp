#include<bits/stdc++.h>

using namespace std;
int N,K;
queue<pair<int,int> > que;
vector<int> arr;
int min_dist = 1000000;
int cases = 0;

int main(){
    cin>>N>>K;
    que.push(make_pair(N,0));
    int dist = 0;
    arr.resize(100001);
    fill(arr.begin(),arr.end(), 1000000);
    arr[N] = 0;

    while(!que.empty()){
        int dist = que.front().second;
        int idx = que.front().first;
        que.pop();
        if(min_dist<dist)
            break;
        if(idx == K){
            if(min_dist>dist){
                min_dist = dist;
                cases = 1;
                continue;
            }
            else if(min_dist==dist){
                cases++;
                continue;
            }
            else{
                continue;
            }
        }

        if(idx+1<=100000){
            if(arr[idx+1] >= dist+1){
                arr[idx+1] = dist+1;
                que.push(make_pair(idx+1, dist+1));
            }
        }
        if(idx-1 >= 0){
            if(arr[idx-1] >= dist+1){
                arr[idx-1] = dist+1;
                que.push(make_pair(idx-1,dist+1));
            }
        }
        if(idx*2<=100000){
            if(arr[idx*2]>=dist+1){
                arr[idx*2] = dist+1;
                que.push(make_pair(idx*2, dist+1));
            }
        }
    }
    cout<<min_dist<<'\n';
    cout<<cases;  
}