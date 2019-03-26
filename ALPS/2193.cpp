//이친수
#include <iostream>
using namespace std;
long long past[2] = {0,1};
long long ans[2] = {1,0};
int main(){
    int n;
    cin>>n;
    for(int i = 1; i<n;i++){
        ans[0] = past[0]+past[1];
        ans[1] = past[0];
        past[0] = ans[0];
        past[1] = ans[1];
    }
    cout<<ans[1]+ans[0];
}
