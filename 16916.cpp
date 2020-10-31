#include<bits/stdc++.h>

using namespace std;
vector<int> pi;
vector<int> getPi(string p){
    pi.resize(p.length());
    int j = 0;
    pi[0] = 0;
    for(int i = 1; i<p.length(); i++){
        while(p[i]!= p[j]){
            if(j==0){
                pi[i] = 0;
                break;
            }
            j = pi[j-1];
        }
        if(p[i]==p[j]){
            pi[i] = ++j;
        }
    }
    return pi;
}

bool kmp(string s,string p){
    int j = 0;
    for(int i = 0; i<s.length(); i++){
        while(s[i]!= p[j]){
            if(j == 0){
                break;
            }
            j = pi[j-1];
        }
        if(s[i] == p[j]){
            j++;
            if(j == p.length()){
                return true;
            }
        }
    }
    return false;
}

int main(){
    string str,p;
    cin>>str>>p;
    getPi(p);
    if(kmp(str,p))
        printf("1");
    else
        printf("0");
}