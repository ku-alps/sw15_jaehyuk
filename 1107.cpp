#include<bits/stdc++.h>

using namespace std;
int broken[10] = {0};
int main(){
    int N,M;cin>>N>>M;
    for(int i = 0; i<M; i++){
        int input; cin>>input;
        broken[input] = 1;
    }
    int ans = abs(100-N);
    for(int i = 0; i<1000000; i++){
        string temp = to_string(i);
        int flag = 1;
        for(int j = 0; j<temp.length(); j++){
            if(broken[temp[j]-'0']==1){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            ans = min((int)temp.length()+abs(i-N),ans);
        }
    }
    cout<<ans<<endl;
}