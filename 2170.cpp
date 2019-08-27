#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair<int,int> arr[1000001];
int N;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin>>N;
    int a,b;
    for(int i = 0; i<N; i++){
        cin>>a>>b;
        arr[i].first = a;
        arr[i].second = b;
    }
    sort(arr,arr+N);
    
    int len = 0;
    int left = arr[0].first;
    int right = arr[0].second;
    len += right-left;
    
    for(int i = 1; i<N; i++){
        if(arr[i].first>right){
            left  = arr[i].first;
            right = arr[i].second;
            len+=  right-left;
        }
        else if(arr[i].first<=right && arr[i].first>=left){
            if(arr[i].second>right){
                len+= arr[i].second-right;
                right = arr[i].second;
            }
        }
    }
    cout<<len<<endl;
}
