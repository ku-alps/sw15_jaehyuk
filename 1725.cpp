#include<bits/stdc++.h>

using namespace std;

vector<int> arr;

int lmax =0;

pair<int,int> hist(int start,int end){
    int mid = (start+end)/2;
    if(start == end)
        return make_pair(arr[start],arr[start]);

    pair<int,int> left = hist(start,mid);
    pair<int,int> right = hist(mid+1,end);
    pair<int,int> _max;
    int cur_min = 0;
    int temp = 0;
    
    if(left.second>right.second){
        _max.first = left.first;
        cur_min = min(left.first,right.first);        
        _max.second = left.second;
        if(_max.second<=(end-start)*cur_min){
            _max.second = (end-start)*cur_min;
            _max.first = cur_min;
        }
        return _max;
    }
    else{
        _max.first = right.first;
        cur_min = min(left.first,right.first);        
        _max.second = right.second;
        if(_max.second<=(end-start)*cur_min){
            _max.second = (end-start)*cur_min;
            _max.first = cur_min;
        }
        return _max;
    }
}

int main(){
    int N;
    cin>>N;
    arr.resize(N+1);
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
    pair<int,int> ans = hist(0,N-1);
    cout<<ans.first<<" "<<ans.second;
}