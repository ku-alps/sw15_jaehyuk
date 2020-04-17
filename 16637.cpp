#include<iostream>
#include<string>
#include<vector>
#include<limits.h>

using namespace std;

int N;
vector<char> arr;

long long calc(char opt, long long a,long long b){
    switch(opt){
        case '*':
            return a*b;
        case '+':
            return a+b;
        case '-':
            return a-b;
    }
    return 0;
}
long long res = INT_MIN;
void dfs(long long sum, int idx){
    if(idx > N-2){
        if(sum>res){
            res = sum;
        }
        return;
    }
    long long case1 = calc(arr[idx],sum,arr[idx+1]-'0');
    dfs(case1, idx+2);

    if(idx+2<=N-2){
        long long case2 = calc(arr[idx+2],arr[idx+1]-'0',arr[idx+3]-'0');
        dfs(calc(arr[idx],sum,case2),idx+4);
    }
}

int main(){
    cin>>N;
    arr.resize(N+1);

    for(int i = 0; i<N; i++)
        cin>>arr[i];

    if(N == 1){
        cout<<arr[0]-'0';
        return 0;
    }
    if(N ==3){
        cout<<calc(arr[1],arr[0]-'0',arr[2]-'0');
        return 0;
    }
    dfs(arr[0]-'0',1);
    cout<<res<<endl;
}