#include<bits/stdc++.h>

using namespace std;

//first:(from, to), second : weight
pair<pair<int,int>,int> box[10001];
int cap[2001];
bool cmp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
    if(a.first.second<b.first.second){
        return true;
    }
    else if(a.first.second>b.first.second){
        return false;
    }
    else{
        if(a.first.first<b.first.first)
            return true;
        else
            return false;
    }
}
int main(){
    int N,C,M;
    cin>>N>>C>>M;
    int ans = 0;
    for(int i = 0; i<M; i++){
        cin>>box[i].first.first>>box[i].first.second>>box[i].second;
    }
    sort(box,box+M,cmp);

    for(int i = 0; i<M; i++){
        int temp = 0;
        for(int j = box[i].first.first; j<box[i].first.second; j++){
            temp = max(temp, cap[j]);
        }
        int surp;
        if(box[i].second>C-temp){
            surp = C-temp;
        }
        else{
            surp = box[i].second;
        }
        ans += surp;
        for(int j = box[i].first.first; j<box[i].first.second; j++){
            cap[j] += surp;
        }
    }
    cout<<ans;
}