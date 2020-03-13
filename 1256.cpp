#include<iostream>

using namespace std;

int N,M,K;
string result = "";

int main(){
    int memo[201][101];
    cin>>N>>M>>K;

    for(int i = 0; i<N+M+1; i++){
        memo[i][0] = 1;
    }
    for(int i = 1; i<N+M+1; i++){
        for(int j = 1; j<i && j<=M; j++){
            memo[i][j] = memo[i-1][j] + memo[i-1][j-1];
            if(memo[i][j]>1000000000)
                memo[i][j] = 1000000000;
        }
        if(i<=M)
            memo[i][i] = 1;
    }
    if(K>memo[N+M][M]){
        cout<<"-1";
        return 0;
    }
    for(int i = M+N-1; i>=0; i--){
        if(i>=M && memo[i][M] > K-1)
            result += "a";
        else{
            result += "z";
            K -= memo[i][M];
            M--;
        }
    }
    cout<<result<<endl;
}