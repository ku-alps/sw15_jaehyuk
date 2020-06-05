#include<bits/stdc++.h>

using namespace std;

int N,K;
vector<int> arr(100001,INT_MAX);
queue<pair<int,int> > que;
int visited[100001] = {0};

int main(){
    cin>>N>>K;
    arr[N]= 0;
    if(N>K){
        cout<<N-K;
        return 0;
    }
    int sec = 0;
    que.push(make_pair(N,0));

    while(!que.empty()){
        int cur = que.front().first;
        sec = que.front().second;
        que.pop();

        if(cur == K){
            cout<<sec;
            return 0;
        }
        if(visited[cur] == 1)
            continue;
        visited[cur] = 1;

        if(cur*2<=100000){
            if(arr[cur*2]>sec+1){
                arr[cur*2] = sec+1;
                que.push(make_pair(cur*2,sec+1));
            }
        }
        if(cur+1<=100000){
            if(arr[cur+1]>sec+1){
                arr[cur+1] = sec+1;
                que.push(make_pair(cur+1,sec+1));
            }
        }
        if(cur-1>=1){
            if(arr[cur-1]>sec+1){
                arr[cur-1] = sec+1;
                que.push(make_pair(cur-1,sec+1));
            }
        }
    }
}