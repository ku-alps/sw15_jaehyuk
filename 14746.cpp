//14746 Closest Pair

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int dist = 300000000;
int distcount = 0;

int main(){
    int n,m;
    cin>>n>>m;
    int c1,c2;
    cin>>c1>>c2;
    
    vector<int> P(n);
    vector<int> Q(m);
    
    for(int i = 0; i<n; i++){
        cin>>P[i];
    }
    sort(P.begin(),P.end());
    for(int i =0; i<m; i++){
        cin>>Q[i];
        
    }
    sort(Q.begin(),Q.end());
    
    int p_ptr = 0;
    int q_ptr = 0;
    int min =300000000;

    //int min = abs(P[p_ptr]-Q[q_ptr]);
    //int cnt=1;
    int cnt = 0;
    while(p_ptr<n && q_ptr<m){
        if(P[p_ptr]>Q[q_ptr]){
            if(abs(P[p_ptr]-Q[q_ptr])<min){
                min = abs(P[p_ptr]-Q[q_ptr]);
                cnt = 1;
            }
            else if(abs(P[p_ptr]-Q[q_ptr])==min){
                cnt++;
            }
            q_ptr++;
        }
        else if(P[p_ptr]<Q[q_ptr]){
            if(abs(P[p_ptr]-Q[q_ptr])<min){
                min = abs(P[p_ptr]-Q[q_ptr]);
                cnt = 1;
            }
            else if(abs(P[p_ptr]-Q[q_ptr])==min){
                cnt++;
            }
            p_ptr++;
        }
        else{
            if(abs(P[p_ptr]-Q[q_ptr]) == min){
                cnt++;
            }
            else if(abs(P[p_ptr]-Q[q_ptr])<min){
                min = abs(P[p_ptr]-Q[q_ptr]);
                cnt = 1;
            }
            p_ptr++;
        }
    }
    
    
    cout<<min+abs(c1-c2)<<" "<<cnt;
}
