#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
int cnt = 0;

vector<int> prime;

void isPrime(int n){
    for(int i = 2; i<n; i++){
        if(prime[i] == false){
            for(int j = i*2; j<n; j+= i){
                prime[j] = true;
            }
        }
    }
    for(int i = 0; i<n; i++){
        prime[i] = !prime[i];
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    prime.resize(1000000);
    fill(prime.begin(),prime.end(),false);
    
    isPrime(1000000);
    
    int n;
    cin>>n;
    while(n != 0){
        
        for(int j = 2; j<=n/2; j++){
            if(prime[j]&&prime[n-j]){
                cout<<n<<" = "<<j<<" + "<<n-j<<'\n';
                break;
            }
            if(j == n/2)
                cout<<"Goldbach's conjecture is wrong."<<'\n';
        }
        
        cin>>n;
    }
}
