#include<bits/stdc++.h>

using namespace std;

int main(){
    long long A,B,C;
    cin>>A>>B>>C;

    long long temp = A;
    
    for(int i = 0; i<B; i++){
        temp = (temp%C) * (temp%C);
    }
    cout<<temp%C;
}