// 2xn타일2
#include <iostream>
using namespace std;
long long ppast=0;
long long past=0;
long long ans=3;
int main(){
    int n;
    cin>>n;
    ppast = 1;
    past = 3;
    for(int i = 2; i<n;i++){
        ans = (past+ppast+ppast)%10007;
        ppast = past;
        past = ans;
    }
    if(n == 1)
        ans=ans-2;
    cout<<ans;
}
