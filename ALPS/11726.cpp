// 2xn타일
#include <iostream>
using namespace std;
long long ppast=0;
long long past=0;
long long ans=1;
int main(){
    int n;
    cin>>n;
    ppast = 1;
    past = 2;
    for(int i = 2; i<n;i++){
        ans = (past+ppast)%10007;
        ppast = past;
        past = ans;
    }
    if(n == 2)
        ans++;
    cout<<ans;
}
