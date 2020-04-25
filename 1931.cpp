#include<bits/stdc++.h>
using namespace std;
pair<int,int> meeting[100001];

bool cmp(pair<int,int> &a ,pair<int,int> &b){
    if(a.second<b.second){
        return true;
    }
    else if(a.second==b.second){
        if(a.first<b.first){
            return true;
        }
    }
    return false;
}
int main(){
    int N;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>meeting[i].first;
        cin>>meeting[i].second;
    }
    sort(meeting,meeting+N,cmp);
    
    int sum = 1;
    int start = meeting[0].first;
    int end = meeting[0].second;
    
    for(int i = 1; i<N; i++){
        if(meeting[i].first == meeting[i].second){
            sum++;
            continue;
        }
        if(meeting[i].first>=end){
            end = meeting[i].second;
            start = meeting[i].first;
            sum++;
        }
    }
    cout<<sum;
}