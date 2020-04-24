#include<bits/stdc++.h>
using namespace std;
queue<pair<long long,int> > que;

int min_dist = -1;

int main(){
    long long A,B;
    cin>>A>>B;
    int dist = 0;
    que.push(make_pair(A,dist));
    while(!que.empty()){
        long long val = que.front().first;
        dist = que.front().second;
        que.pop();
        if(val>B){
            continue;
        }
        if(val == B){
            min_dist = dist+1;
            break;
        }
        if(val*2<=B){
            que.push(make_pair(val*2,dist+1));
        }
        if(val*10+1<=B){
            que.push(make_pair(val*10+1,dist+1));
        }
    }
    cout<<min_dist;
}