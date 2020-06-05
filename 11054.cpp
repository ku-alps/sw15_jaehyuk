#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int N;
int arr[1001];
int dp[1001];
vector<int> temp;
int bs(int key){
    int start = 0,end = temp.size()-1;
    while(start<=end){ 
        int mid = (start+end)/2;
        if(temp[mid] == key){
            return mid;
        }
        else if(temp[mid]<key){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return start;
}
void func(){
    temp.push_back(arr[0]);
    for(int i = 1; i<N; i++){
        int k = bs(arr[i]);
        if(k == temp.size()){
            temp.push_back(arr[i]);
        }
        else{
            temp[k] = arr[i];
        }
        dp[i] += temp.size();
    }
    temp.clear();
    temp.resize(0);
    temp.push_back(arr[N-1]);
    for(int i = N-2; i>=0; i--){
        int k = bs(arr[i]);
        if(k == temp.size()){
            temp.push_back(arr[i]);
        }
        else{
            temp[k] = arr[i];
        }
        dp[i] += temp.size();
    }
}
int main(){
    cin>>N;
    memset(dp,0,sizeof(dp));
    for(int i =0; i<N; i++)
        cin>>arr[i];
    dp[0] = 1;
    dp[N-1] += 1;
    func();
    int ans = 0;
    for(int i = 0; i<N; i++)
        ans = max(ans,dp[i]-1);
    cout<<ans;
}