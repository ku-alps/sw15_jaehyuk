#include<iostream>
#include<string>
#include<vector>

using namespace std;

int N;
vector<char> arr;

vector<vector<int> > dp;

int calc(char opt, int a,int b){
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

int main(){
    cin>>N;
    arr.resize(N+1);
    dp.resize(N+1);
    for(int i = 0; i<N; i++)
        dp[i].resize(2);
    for(int i = 0; i<N; i++)
        cin>>arr[i];

    if(N == 1){
        cout<<arr[0]-'0';
        return 0;
    }
    if(N==3){
        cout<<calc(arr[1],arr[0]-'0',arr[2]-'0');
        return 0;
    }
    if(N>=5){
        dp[1][0] = arr[0]-'0';
        dp[1][1] = calc(arr[1],arr[0]-'0',arr[2]-'0');
        
        dp[3][0] = max(dp[1][1],calc(arr[1],dp[1][0],arr[2]-'0'));
        dp[3][1] = calc(arr[1],dp[1][0],calc(arr[3],arr[2]-'0',arr[4]-'0'));
    }
    //cout<<dp[3][0]<<endl;
    //cout<<dp[3][1]<<endl;
    
    //i=5
    for(int i = 5; i<N; i+=2){
        dp[i][0] = max(dp[i-2][1],max(calc(arr[i-2],dp[i-2][0],arr[i-1]-'0'),calc(arr[i-2],dp[i-4][1],arr[i-1]-'0')));
        dp[i][1] = max(calc(arr[i-2],dp[i-4][1],calc(arr[i],arr[i-1]-'0',arr[i+1]-'0')),
                        calc(arr[i-2],dp[i-2][0],calc(arr[i],arr[i-1]-'0',arr[i+1]-'0')));
        //cout<<i<<": "<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    //cout<<dp[N-2][0]<<endl;
    //cout<<calc(arr[N-2],dp[N-2][0],arr[N-1]-'0')<<" "<<dp[N-2][1];
    
    cout<<max(calc(arr[N-2],dp[N-2][0],arr[N-1]-'0'),dp[N-2][1]);
    
    /*
    dp[5][0] = max(dp[3][1],max(calc(arr[3],dp[3][0],arr[4]-'0'),calc(arr[3],dp[1][1],arr[4]-'0')));
    dp[5][1] = max(calc(arr[3],dp[1][1],calc(arr[5],arr[4]-'0',arr[6]-'0')),
                    calc(arr[3],dp[3][0],calc(arr[5],arr[4]-'0',arr[6]-'0')));
    cout<<dp[5][0]<<endl;
    cout<<dp[5][1]<<endl;
   
    cout<<calc(arr[5],dp[5][0],arr[6]-'0')<<" "<<dp[5][1];
    */

    /*
    dp[7][0] = max(dp[5][1],max(calc(arr[5],dp[5][0],arr[6]-'0'),calc(arr[5],dp[3][1],arr[6]-'0')));
    dp[7][1] = max(calc(arr[5],dp[3][1],calc(arr[7],arr[6]-'0',arr[8]-'0')),
                    calc(arr[5],dp[5][0],calc(arr[7],arr[6]-'0',arr[8]-'0')));

    cout<<calc(arr[7],dp[7][0],arr[8]-'0')<<" "<<dp[7][1];
    */
   
}