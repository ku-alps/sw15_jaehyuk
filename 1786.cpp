#include<bits/stdc++.h>

using namespace std;
vector<int> pi;
vector<int> getPi(string p){
    
    pi[0] = 0;
    int j = 0;
    for(int i = 1; i<(int)p.length(); i++){
        while(p[i]!=p[j]){
            //이전 값이 없으므로
            if(j==0){
                //접미사 접두사 둘다 길이가 1일떄는 같지 않을때 항상 pi[1] = 0
                pi[i] = 0;
                break;
            }
            //뛰어넘을 곳 정하기
            j = pi[j-1];
        }
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}
vector<int> kmp(string t,string p){
    vector<int> v;
    int j = 0;
    for(int i = 0; i<t.length(); i++){
        while(t[i]!=p[j]){
            if(j == 0){
                break;
            }
            j = pi[j-1];
        }
        if(t[i] == p[j]){
            j++;
            if(j == p.length()){
                v.push_back(i-p.length()+2);
                j = pi[j-1];
            }
        }
    }
    return v;
}

int main(){
    string T,P;
    getline(cin, T);
    getline(cin, P);
    pi.resize(int(P.length()));
    pi = getPi(P);
    vector<int> v = kmp(T,P);
    cout<<v.size()<<endl;
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<< " ";
    }
    return 0;
}