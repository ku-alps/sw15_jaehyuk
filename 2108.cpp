#include<bits/stdc++.h>
#include<cmath>

using namespace std;

vector<int> arr(500001);
vector<pair<int, int> > freq(8001,make_pair(0,0));

bool cmp(pair<int,int> &a, pair<int, int>&b){
    if(a.first>b.first){
        return true;
    }
    else if(a.first == b.first){
        if(a.second<b.second){
            return true;
        }
    }
    return false;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N;cin>>N;
    double sum = 0;
    for(int i = 0; i<N; i++){
        cin>>arr[i];
        sum+= arr[i];
        if(arr[i]<0){
            freq[4000+abs(arr[i])].first++;
            freq[4000+abs(arr[i])].second = arr[i];
        }
        else{
            freq[arr[i]].first++;
            freq[arr[i]].second = arr[i];
        }
    }
    double avg = sum/N;
    cout<<int(round(avg))<<'\n';
    sort(arr.begin(),arr.begin()+N);
    
    cout<<arr[(N-1)/2]<<'\n';
    sort(freq.begin(),freq.end(),cmp);
    /*
    for(int i = 0; i<N; i++){
        cout<<freq[i].second<<" ";
    }
    cout<<endl;
    */
    int k = 0;
    if(N>1){
        if(freq[0].first == freq[1].first){
            cout<<freq[1].second<<'\n';
        }
        else{
            cout<<freq[0].second<<'\n';
        }
    }
    else
    {
        cout<<freq[0].second<<'\n';
    }
    cout<<arr[N-1] - arr[0]<<'\n';
}