#include<bits/stdc++.h>

using namespace std;

int main(){
    long long A,B,C;
    cin>>A>>B>>C;

    long long temp = A;
    
    for(int i = 0; i<B; i++){
        if(temp>C){
            temp %= C;
        }
        temp *=temp;
    }
    cout<<temp%C;
}