#include<cstdio>
#include<vector>
#include<queue>
#include<climits>

using namespace std;
//vector<vector<int>> weight;
struct node{
    int key = INT_MAX;
    int conn = -1;
};
vector<vector<pair<int,int>>> weight;
int v,e;
vector<node> vertex;
vector<int> visited;
queue<int> que;
pair<int,int>* pq;
int cnt = 0;
long long ans = 0;

//priority queue init
void pq_push(int val,int conn){
    pq[cnt].first = val;
    pq[cnt].second = conn;
    int temp = cnt;
    cnt++;
    while(temp){
        if(pq[(temp-1)/2].first > pq[temp].first){
            pq[temp].swap(pq[(temp-1)/2]);
//            swapData(pq,(temp-1)/2,temp);
        }
        else
            break;
        
        temp = (temp-1)/2;
    }
}
pair<int,int> pq_pop(){
    
    pair<int,int> ans = make_pair(pq[0].first,pq[0].second);
    pq[0].swap(pq[cnt-1]);
    //swapData(pq,0,cnt-1);
    int temp = 0;
    
    while((temp*2+1)<cnt-1)
    {
        if((temp*2+2)>=cnt-1)//right child not exists
        {
            if(pq[temp*2+1].first<pq[temp].first){
                pq[temp*2+1].swap(pq[temp]);
                break;
            }
            else
                break;
        }
        if(pq[temp*2+1].first<pq[temp*2+2].first)
        {
            if(pq[temp*2+1].first<pq[temp].first){
                pq[temp*2+1].swap(pq[temp]);
                temp = temp*2 +1;
            }
            else
                break;
        }
        else{
            if(pq[temp*2+2].first<pq[temp].first){
                pq[temp*2+2].swap(pq[temp]);
                temp = temp*2 +2;
            }
            else
                break;
        }
        
    }
    cnt--;
    return ans;
}



void bfs(int start){
    pq_push(0,start);
    
    for(int k = 0; k<v; k++){
        
        int dmin = INT_MAX;
        int cur=start;
        
        while(cnt>0){
            pair<int,int> temp = pq_pop();
            cur = temp.second;
            
            if(visited[cur] == 0){
                dmin = temp.first;
                break;
            }
        }
        if(dmin == INT_MAX)
            return;
        
        ans += dmin;
        visited[cur] = 1;
        for(int i = 0; i<weight[cur].size(); i++){
            pq_push(weight[cur][i].second,weight[cur][i].first);
        }
        /*
        for(int i = 0; i<weight[cur].size(); i++){
            
            if(vertex[cur].conn == weight[cur][i].first){
                continue;
            }*/
            /*
            if(vertex[weight[cur][i].first].key>weight[cur][i].second)
            {
                vertex[weight[cur][i].first].conn = cur;
                vertex[weight[cur][i].first].key = weight[cur][i].second;
                pq_push(vertex[weight[cur][i].first].key,weight[cur][i].first);
            }
        }*/
    }
}

int main(){

    scanf("%d %d",&v,&e);
    int a,b,c;
    pq = new pair<int,int>[200001];
    weight.resize(10001);
    vertex.resize(10001);
    visited.resize(10001);
    fill(visited.begin(),visited.end(),0);
 
    for(int i = 0; i<e; i++){
        scanf("%d %d %d",&a,&b,&c);
        weight[a-1].push_back(make_pair(b-1, c));
        weight[b-1].push_back(make_pair(a-1, c));
    }
    bfs(a-1);
    printf("%lld\n",ans);
}
