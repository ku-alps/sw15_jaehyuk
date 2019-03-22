//연속합
#include <iostream>
using namespace std;

int arr[100000];
int _max[100000];

int main(){
    int n;
    cin>>n;
    int num;
    
    for(int i = 0; i<n; i++){
        cin>>num;
        arr[i] = num;
        if(i == 0)
            _max[0] = arr[0];
        else
            _max[i] = max(arr[i],_max[i-1]+arr[i]);
    }
    int ans = -1001;
    for(int i = 0; i<n; i++){
        if(_max[i]>ans)
            ans = _max[i];
    }
    cout<<ans<<endl;
}
