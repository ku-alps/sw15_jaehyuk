#include<iostream>
#include<algorithm>

using namespace std;

long long data[1004] = {0};
long long cache[1004] = {0};
pair<long long,long long> lis[1004];

long long LB(long long* arr, long long left,long long right,long long key){
    //가정 : 중복 없음
    while(left<right){
        
        long long mid = (left+right)/2;
        
        if(key > arr[mid])
            left = mid+1;
        else if(key < arr[mid])
            right = mid-1;
        //같은 값이면 그 원소의 위치
        else
            return mid;
    }
    //left>=right일때 반복문 탈출
    
    if(arr[left]<key){
        //마지막 원소
        return left+1;
    }
    else
        return left;
}
int main(){
    long long n;
    cin>>n;
    long long a;
    
    for(long long i = 0 ; i<n; i++){
        cin>>a;
        data[i] = a;
    }
    cache[0] = data[0];
    lis[0].first = 0;
    lis[0].second = 0;
    
    long long index = 0;
    
    for(long long i = 1; i<n; i++){
        //마지막 수보다 데이터가 큰 경우 : 추가
        if(cache[index] < data[i]){
            cache[index+1] = data[i];
            lis[i].first = i;
            lis[i].second = index+1;
            index++;
        }
        //마지막 수가 데이터보다 큰 경우 : 대치
        else if(cache[index] > data[i]){
            lis[i].first = i;
            lis[i].second = LB(cache,0,index,data[i]);
            cache[lis[i].second] = data[i];
        }
        //마지막 수와 데이터가 같은 경우 : 대치
        else{
            lis[i].first = i;
            lis[i].second = index;
            cache[lis[i].second] = data[i];
        }
    }
    cout<<index+1<<endl;
    long long length = index+1;
    for(long long i = n; i>=0; i--){
        if(lis[i].second == index){
            cache[index] = data[lis[i].first];
            index--;
        }
    }
    for(long long i = 0; i<length;i++)
        cout<<cache[i]<<" ";
}
