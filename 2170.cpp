#include<bits/stdc++.h>

using namespace std;

//vector<pair<int,int> > arr;
pair<int,int> arr[1000001];
bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first<b.first){
        return true;
    }
    else if(a.first==b.first){
        if(a.second>b.second){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N;
    cin>>N;
    int start=INT_MIN,end=INT_MIN;
    int a,b;
    for(int i = 0; i<N; i++){
        cin>>a>>b;
        arr[i].first = a;
        arr[i].second = b;
    }
    sort(arr,arr+N,cmp);
    int len = 0;
    for(int i=0; i<N; i++){
        if(start<arr[i].first){
            if(end<arr[i].first){
                len += end-start;
                start = arr[i].first;
                end = arr[i].second;
            }
            else{
                if(arr[i].second>end){
                    end = arr[i].second;
                }
            }
        }      
        if(i == N-1){
            len+=end-start;
        }
    }
    cout<<len;
/*
    for(int i = 0; i<N; i++){
        cout<<arr[i].first<<","<<arr[i].second<<endl;
    }
*/
}
