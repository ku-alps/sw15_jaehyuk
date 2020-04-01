#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N;cin>>N;
    vector<long long> a(N),b(N),c(N),d(N);
    vector<long long> x(N*N); vector<long long> y(N*N);
    for(int i = 0; i<N; i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    int k = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            x[k] = a[i]+b[j];
            y[k] = c[i]+d[j];
            k++;
        }
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    long long sum = 0;
    for(int i = 0; i<x.size(); i++){
        int start = 0,end = y.size()-1;
        long long key = x[i]*(-1);
        int k = (start+end)/2;

        while(start<end){
            if(y[k]<key){
                start = k;
                k = (start+end+1)/2;
            }
            else if(y[k]>=key){
                end = k-1;
                k = (start+end)/2;
            }
        }   
        int lb = k;
        if(y[lb]>=key){
            lb -=1;
        }
        start = 0,end = y.size()-1;
        k = (start+end)/2;
        while(start<end){
            if(y[k]<=key){
                start = k+1;
                k = (start+end)/2;
            }
            else if(y[k]>key){
                end = k;
                k = (start+end)/2;
            }
        }   
        int ub = k;
        if(y[ub]<=key){
            ub+=1;
        }
        if(ub-lb-1 >=1){
            sum+=ub-lb-1;
        }
    }
    cout<<sum;
}