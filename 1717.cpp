#include<iostream>
#include<vector>

using namespace std;
int n,m;
vector<int> s;

int find(int a){
    if(s[a] < 0)
        return a;
    else{
        s[a] = find(s[a]);
        return s[a];
    }
}
void merge(int a,int b){
    int x = find(a);
    int y = find(b);
    if(x==y)
        return;
    else{
        //큰 집합(depth가)이 작은 집합의 루트가 되게
        if(s[x] < s[y])
        //x루트의 집합크기가 더 큼
        {
            s[x] += s[y];
            s[y] = x;
        }
        else
        //y루트의 집합크기가 더 큼
        {
            s[y] += s[x];
            s[x] = y;
        }
        
        
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n>>m;
    
    s.resize(n+1);
    fill(s.begin(),s.end(),-1);
    
    int calc;
    int a,b;
    for(int i = 0; i<m; i++){
        cin>>calc;
        cin>>a>>b;
        //find
        if(calc == 1){
            if(find(a)==find(b))
                cout<<"YES"<<'\n';
            else
                cout<<"NO"<<'\n';
        }
        //union
        else{
            merge(a,b);
        }
    }
}
