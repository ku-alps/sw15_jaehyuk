/*

    1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
    2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
    3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
    4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
vector<vector<int> > A;
vector<int> ans;
vector<int> D;
// y>d1
// y<N-d2

// x<N-d1
// x<N-d1-d2
// d1<N-d2-x
int main(){
    cin>>N;
    A.resize(N+1);
    D.resize(5);
    for(int i = 0; i<N+1; i++)
        A[i].resize(N+1);
    for(int i = 1; i<N+1; i++){
        for(int j = 1; j<N+1; j++){
            cin>>A[i][j];
        }
    }
    for(int x = 1; x<N; x++){
        for(int y = 2; y<N; y++){
            for(int d2 = 1; d2<=N-y; d2++){
                for(int d1 = 1; (d1<=N-d2-x && 1<=y-d1); d1++){
                    fill(D.begin(),D.end(),0);
                    for(int i = 1; i<N+1; i++){
                        for(int j = 1; j<N+1; j++){
                            if(
                            (j+i>=x+y)&&
                            (j-i<=y-x)&&
                            (j-i>=y-x-2*d1)&&
                            (j+i<=x+y+2*d2))
                                D[4]+=A[i][j];
                            
                            else if((i<x+d1)&&(j<=y))
                                D[0]+=A[i][j];
                            else if((i<=x+d2)&&(y<j))
                                D[1]+=A[i][j];
                            else if((x+d1<=i)&&(j<y-d1+d2))
                                D[2]+=A[i][j];
                            else if((x+d2<i)&&(y-d1+d2<=j))
                                D[3]+=A[i][j];
                            
                        }
                    }
                    /*
                    cout<<"x:"<<x<<" y:"<<y<<" d1:"<<d1<<" d2:"<<d2<<endl;
                    for(int k = 0; k<5; k++){
                        
                        cout<<D[k]<<" ";
                    }
                    cout<<endl;
                    */
                    sort(D.begin(),D.end());
                    ans.push_back(abs(D[0]-D[4]));
                }
            }
        }
    }
    sort(ans.begin(),ans.end(),greater<int>());
    cout<<ans[ans.size()-1]<<endl;
    //cout<<ans[0]<<endl;
}
