#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int m,n,l;
int pad[100001];
pair<int,int> pnt[100001];
pair<int,int> sorted[100001];
int visited[100001] = {0};

int cnt = 0;

bool cmpX(pair<int,int>& a, pair<int,int>& b){
    if(a.first<b.first)
        return true;
    else if(a.first == b.first){
        return a.second<b.second;
    }
    else
        return false;
}

bool inBoundary(int x,int y,int pad_x){

    if(abs(pad_x-x)+y<=l)
        return true;
    return false;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>m>>n>>l;
    
    int input;
    for(int i = 0; i<m; i++){
        cin>>input;
        pad[i] = input;
    }
    sort(pad,pad+m);
    
    int x,y;
    int cn = 0;
    for(int i = 0; i<n; i++){
        cin>>x>>y;
        if(y<=l){
            pnt[cn] = make_pair(x,y);
            cn++;
        }
    }

    sort(pnt,pnt+cn,cmpX);

    int ans = 0;
    int pad_cnt = 0;
    
    for(int i = 0; i<cn; i++){
        //좌상향
        if(pnt[i].first<=pad[pad_cnt] && pnt[i].first>=pad[pad_cnt]-l){
            if(inBoundary(pnt[i].first, pnt[i].second, pad[pad_cnt])){
                visited[i] = 1;
                while(i+1<cn && pnt[i].first == pnt[i+1].first){
                    if(inBoundary(pnt[i+1].first,pnt[i+1].second,pad[pad_cnt])){
                        
                        visited[i+1] = 1;
                        i++;
                    }
                    else{
                        i++;
                    }
                }
            }
        }
        
        else if(pnt[i].first>pad[pad_cnt]){
            pad_cnt++;
            i--;
            if(pad_cnt==m){
                i++;
                pad_cnt--;
            }
        }
    }
    pad_cnt = m-1;
    
    for(int i = cn-1; i>=0; i--){
        //우하향을 오른쪽부터
        if(pnt[i].first>pad[pad_cnt] && pnt[i].first<=pad[pad_cnt]+l){
            if(inBoundary(pnt[i].first, pnt[i].second, pad[pad_cnt])){
                visited[i] = 1;
                while(i-1>=0 && pnt[i].first == pnt[i-1].first){
                    if(inBoundary(pnt[i-1].first,pnt[i-1].second,pad[pad_cnt])){
                        visited[i-1] = 1;
                        i--;
                    }
                    else{
                        i--;
                    }
                }
            }
        }
        
        else if(pnt[i].first<pad[pad_cnt]){
            pad_cnt--;
            i++;
            if(pad_cnt==-1){
                i--;
                pad_cnt++;
            }
        }
    }
    for(int i = 0; i<cn; i++){
        ans+= visited[i];
    }
    cout<<ans<<endl;
}
