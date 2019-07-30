#include<iostream>
#include<vector>

using namespace std;

int n,l;
vector<int> arr;
vector<int> used;

int find(int idx){
    if(arr[idx] < 0)
        return idx;
    arr[idx] = find(arr[idx]);
    return arr[idx];
}

void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    arr[b] += arr[a];
    arr[a] = b;
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    cin>>n>>l;
    int a,b;
    arr.resize(l);
    fill(arr.begin(),arr.end(),-1);
    used.resize(l);
    fill(used.begin(),used.end(),0);
    
    for(int i = 0; i<n; i++){
        cin>>a>>b;
        a -= 1;
        b -= 1;
        if(used[a] == 0)
        {
            merge(a,b);
            used[a] = 1;
            cout<<"LADICA"<<'\n';
            
        }else if(used[b] == 0){
            merge(b,a);
            used[b] = 1;
            cout<<"LADICA"<<'\n';
        }
        else if(used[find(a)] == 0){
            used[find(a)] = 1;
            cout<<"LADICA"<<'\n';
            merge(a,b);
        }
        else if(used[find(b)] == 0){
            used[find(b)] = 1;
            cout<<"LADICA"<<'\n';
            merge(b,a);
        }
        else
            cout<<"SMECE"<<'\n';
    }
}
