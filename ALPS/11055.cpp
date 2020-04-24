#include <iostream>
using namespace std;
int main(){
    int cache[1000] = {0}, data[1000] = {0};
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }
    int _max = 0;
    
    for(int i = 0; i < n; i++){
        cache[i] = data[i];
        for(int j = 0; j < i; j++){
            if(data[j] < data[i] && cache[i] < cache[j] + data[i])
                cache[i] = cache[j] + data[i];
        }
    }
    for(int i = 0; i<n;i++){
        if(_max<cache[i])
            _max = cache[i];
    }
    
    cout << _max;
}
