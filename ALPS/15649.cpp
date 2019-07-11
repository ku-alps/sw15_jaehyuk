#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> arr;
int visited[9];

void foo(int ptr)
{
    if(ptr == m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<" ";
        cout<<'\n';
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            arr.push_back(i);
            visited[i] = 1;
            foo(ptr+1);
            arr.pop_back();
            visited[i] = 0;
        }
    }
    return;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin>>n>>m;
    foo(0);
}
