#include<iostream>
#include<vector>
using namespace std;

vector<long long> cases;
vector<long long> arr;
int N,M;

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        cases.resize(10001);
        fill(cases.begin(),cases.end(),0);
        arr.resize(N+1);
        fill(arr.begin(),arr.end(),0);

        for(int i = 1 ;i<N+1; i++){
            cin>>arr[i];
        }
        cin>>M;
        //cases는 i를 만들수 있는 경우의 수
        //cases[0] = 1;
        cases[arr[0]] = 1;
        for(int i = 1; i<N+1; i++){
            for(int j = arr[i]; j<=M; j++){
                if(j-arr[i]>=0)
                    cases[j] += cases[j-arr[i]];
            }
        }
        cout<<cases[M]<<'\n';
    }
}