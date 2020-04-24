#include<bits/stdc++.h>
using namespace std;
int A,P;
int visited[1000000] = {0};
queue<int> que;
int main(){
    cin>>A>>P;
    int cnt = 0;
    que.push(A);
    while(!que.empty()){
        int idx = que.front();
        que.pop();
        cnt++;
        if(visited[idx] != 0){
            cout<<visited[idx]-1<<endl;
            break;
        }   
        visited[idx] = cnt;
        string str = to_string(idx);
        int sum = 0;
        for(int i= 0; i<str.length(); i++){
            sum += pow((int)(str[i]-'0'),P);
        }
        que.push(sum);
    }
}