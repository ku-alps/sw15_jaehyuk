#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
int N;
int arr[8];
int visited[8];
vector<int> temp;
int ans = 0;
void calc(){
    int sum = 0;
    for(int i = 0; i<temp.size()-1; i++){
        sum += (abs(temp[i]-temp[i+1]));
    }
    ans = max(ans,sum);
}
int func(int cnt){
    if(cnt == N){
        calc();
        return 0;
    }
    for(int i = 0; i<N; i++){
        if(visited[i] == 1){
            continue;
        }
        visited[i] = 1;
        temp.push_back(arr[i]);
        func(cnt+1);
        visited[i] = 0;   
        temp.pop_back();     
    }
    return 0;
}
int main(){
    memset(visited,0,sizeof(visited));
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
    func(0);
    cout<<ans;
}