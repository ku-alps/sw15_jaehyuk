#include<iostream>
#include<algorithm>

using namespace std;

long data[1000004] = {0};
long cache[1000004] = {0};

void BS(long* arr, long left,long right,long key){
    while(left<right){
        long mid = (left+right)/2;
        
        if(key > arr[mid])
            left = mid+1;
        else if(key < arr[mid])
            right = mid-1;
        else
            return;
    }
    if(key>arr[left])
        arr[left+1] = key;
    else
        arr[left] = key;
}
int main(){
    long n;
    cin>>n;
    long a;
    
    for(long i = 0 ; i<n; i++){
        cin>>a;
        data[i] = a;
    }
    cache[0] = data[0];
    long index = 0;
    for(long i = 1; i<n; i++){
        if(cache[index] < data[i]){
            cache[index+1] = data[i];
            index++;
        }
        else if(cache[index] > data[i]){
            BS(cache, 0, index, data[i]);
        }
    }
    cout<<index+1<<endl;
}
