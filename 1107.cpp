/*#include<bits/stdc++.h>

using namespace std;
int broken[10] = {0};
int main(){
    int N,M;cin>>N>>M;
    for(int i = 0; i<M; i++){
        int input; cin>>input;
        broken[input] = 1;
    }
    int ans = abs(100-N);
    for(int i = 0; i<1000000; i++){
        string temp = to_string(i);
        int flag = 1;
        for(int j = 0; j<temp.length(); j++){
            if(broken[temp[j]-'0']==1){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            ans = min((int)temp.length()+abs(i-N),ans);
        }
    }
    cout<<ans<<endl;
}*/

#include <iostream>
#include <algorithm>
using namespace std;
int N, M, broken, button[10];
int _min;
void func(int n, int cnt){
    if(cnt > 6) return;
    if(n > N){
        _min = min(_min, n-N + cnt);
        return;
    }
	_min = min(_min, N-n + cnt);
	for(int i=0; i<10; i++){
		if(button[i] != -1){
			func(n*10 + i, cnt + 1);
		}
	}
	return;
}

int main(){
	cin >> N;
	cin >> M;
	_min = abs(N - 100);
	for(int i=0; i<10; i++){
		button[i] = i;
	}
	
	for(int i=0; i<M; i++){
		cin >> broken;
		button[broken] = -1;
	}
	
	for(int i=0; i<10; i++){
		if(button[i] != -1){
			func(i, 1);
		}
	}
	
	cout << _min << endl;
	
	return 0;
}