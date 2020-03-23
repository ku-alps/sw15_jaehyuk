#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;

vector<int> arr;
vector<pair<int,int> > ans;

int bs(int idx){
    int start = 0;
    int end = N-1;
    int k = (start+end)/2;
    while(start<end){
        if(arr[idx]<ans[k].first){
            end = k;
            k = k/2;
        }
        else if(arr[idx]>ans[k].first){
            start = k+1;
            k = (k+end)/2;
        }
        else{
            if(idx == ans[k].second){
                return k; 
            }
            else if(idx > ans[k].second){
                start = k+1;
                k = (k+end)/2;
            }
            else{
                end = k;
                k = k/2;
            }
        }
    }
    return start;
}

int main(){
    cin>>N;
    int input;
    for(int i = 0; i<N; i++){
        cin>>input;
        arr.push_back(input);
        ans.push_back(make_pair(input,i));
    }
    stable_sort(ans.begin(),ans.end());
    int sum =0;

    for(int i = 0; i<N; i++){
        cout<<ans[i].first<<" , "<<ans[i].second<<" ";
    }
    cout<<endl;

    for(int i = 0; i<N; i++){
        sum += abs(i-bs(i));
    }
    cout<<sum<<endl;
}