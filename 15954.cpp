#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> D;
int N,K;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    D.resize(501);
    cin>>N>>K;
    for(int i = 0; i<N; i++)
        cin>>D[i];
    int cur,_K = K;
    long double _stdev = -1,sum, _avg, temp;
    while(_K<=N){
        cur = 0;
        while(cur+_K<=N){
            sum = 0;
            temp = 0;
            //평균구하기
            for(int i = cur; i<cur+_K; i++)
                sum += D[i];
            _avg = sum/_K;
            //각 개체 - 평균
            for(int i = cur; i<cur+_K; i++)
                temp += pow(D[i]-_avg,2);
            
            temp = sqrt(temp/_K);
            if(_stdev == -1)
                _stdev = temp;
            else{
                if(_stdev > temp)
                    _stdev = temp;
            }
            cur++;
        }
        _K++;
    }
    cout.setf(ios::fixed);
    cout.precision(11);
    cout<<_stdev<<'\n';
    return 0;
}