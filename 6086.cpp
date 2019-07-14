//최대유량
#include<iostream>
#include<deque>

using namespace std;

struct node;

struct edge{
    int to;
    int cap;
    edge* prev;
    edge(int to,int cap):to(to),cap(cap){}
};

int visited[100] = {0};
deque<deque<edge*>> adj(100);

int dfs(int p, int cap){
    if(visited[p] == 1)
        return 0;
    visited[p] = 1;
    
    if(p == 25)
        return cap;
    
    for(int i = 0; i<adj[p].size(); i++){
        if(adj[p][i]->cap>0){
            int temp= adj[p][i]->cap;
            
            //루트일때 조건 추가
            if(cap!= 0 && temp>cap){    //직렬연결 시 작은값으로
                temp = cap;
            }
            
            int flow = dfs(adj[p][i]->to, temp);
            
            if(flow){   //경로 찾음
                adj[p][i]->cap -= flow;  //정방향 자원 소비
                (adj[p][i]->prev)->cap += flow;
                
                return flow;
            }
        }
    }
    return 0;
}
int ford_fullkerson(int start){
    int ans = 0;
    while(true){
        int flow;
        for(int i = 0; i<100; i++)
            visited[i] = 0;
        flow = dfs(start,0);
        if(flow == 0)
            break;
        ans += flow;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    char from = 0,to = 0;
    int weight;
    
    for(int i = 0; i<n; i++){
        cin>>from;
        
        if(from >= 'A' && from<= 'Z')
            from -= 'A';
        else if(from >= 'a'&& from<= 'z')
            from -= 'a'-26;
        
        
        cin>>to;

        if(to >= 'A' && to<= 'Z')
            to -= 'A';
        else if(to >= 'a'&& to<= 'z')
            to -= 'a'-26;
        
        
        cin>>weight;
        
        edge *e = new edge(to,weight);
        edge *e2 = new edge(from,0);
        
        e2->prev = e;
        e->prev = e2;
        
        adj[from].push_back(e);
        adj[to].push_back(e2);
        
        //========================
        
        *e = edge(from,weight);
        *e2 = edge(to,0);
        
        e2->prev = e;
        e->prev = e2;
        
        adj[to].push_back(e);
        adj[from].push_back(e2);
        
    }
    
    cout<<ford_fullkerson(0)<<endl;
}
