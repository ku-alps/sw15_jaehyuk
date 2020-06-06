#include<bits/stdc++.h>

using namespace std;
long long A,B,C;
int calc(long long num,int cnt){
    if(cnt == 1){
        return num%C;
    }
    if(cnt == 0){
        return 1;
    }
    if(cnt %2 == 0){
        num = calc(num,cnt/2)%C;
        return (num*num)%C;
    }
    return (num*calc(num,cnt-1)%C)%C;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin>>A>>B>>C;
    long long temp = A;
    if(B == 1){
        cout<<A%C;
        return 0;
    }
    cout<<calc(A,B)%C;
}