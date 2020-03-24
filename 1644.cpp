#include<iostream>
#include<vector>

using namespace std;
vector<int> prime;

int main(){
    int N;
    cin>>N;
    vector<bool> isPrime(4000000,1);
    isPrime[1] = 0;
    for(int i = 2; i<=N; i++){
        for(int j = 2; i*j<=N; j++){
            if(isPrime[i] == 1){
                isPrime[i*j] = 0;
            }
        }
    }
    for(int i = 1; i<=N; i++){
        if(isPrime[i] == 1){
            prime.push_back(i);
        }
    }
    /*
    for(int i = 0; i<prime.size(); i++){
        cout<<prime[i]<<" ";
    }
    */
   int ans = 0;
   for(int i = 0; i<prime.size(); i++){
       int sum = prime[i];
       int k = 1;
       while(prime.size()>i+k && sum<N){
           sum += prime[i+k];
           k++;
           //cout<<sum<<endl;
       }
       if(sum == N){
           ans++;
       }
   }
   cout<<ans<<endl;
}