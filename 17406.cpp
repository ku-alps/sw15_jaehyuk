#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,M,K;
int A[51][51];
int temp[51][51];
vector<int> sum;
vector<int> ans;
void calc(int r,int c, int s){
    for(int j = 0; j<s; j++){
        int loop = (j+1)*2+1;
        int first = temp[r-(j+1)][c-(j+1)];
        for(int k = 0; k<loop-1; k++){
            temp[r-(j+1)+k][c-(j+1)] = temp[r-(j)+k][c-(j+1)];
        }
        for(int k = 0; k<loop-1; k++){
            temp[r+(j+1)][c-(j+1)+k] = temp[r+(j+1)][c-(j)+k];
        }
        for(int k = 0; k<loop-1; k++){
            temp[r+(j+1)-k][c+(j+1)] = temp[r+(j)-k][c+(j+1)];
        }
        for(int k = 0; k<loop-1; k++){
            temp[r-(j+1)][c+(j+1)-k] = temp[r-(j+1)][c+(j)-k];
        }
        temp[r-(j+1)][c-(j+1)+1] = first;
    }
}
int main(){
    cin>>N>>M>>K;
    sum.resize(N);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>A[i][j];
            temp[i][j] = A[i][j];
        }
    }
    int r,c,s;
    vector<pair<int,pair<int,int> > > vec;

    for(int i =0; i<K; i++){
        cin>>r>>c>>s;
        r--;c--;
        vec.push_back(make_pair(r,make_pair(c,s)));
    }
    
    int arr[K];

    for(int i = 0; i<K; i++){
        arr[i] = i;
    }
    //K가 가지는 모든 순열
    do{
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                temp[i][j] = A[i][j];
            }
        }
        for(int i = 0; i<K; i++){
            calc(vec[arr[i]].first,vec[arr[i]].second.first,vec[arr[i]].second.second);   
        }
        fill(sum.begin(),sum.end(),0);
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                sum[i] += temp[i][j];       
            }
        }
        sort(sum.begin(),sum.end());
        ans.push_back(sum[0]);
    }while(next_permutation(arr,arr+K));

    sort(ans.begin(),ans.end());
    cout<<ans[0]<<endl;
}