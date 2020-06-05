#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int arr[500000];
long long ans = 0;
void merge(int a,int b,int c){
    vector<int> sorted;
    sorted.resize(c-a+1);
    int k = 0,i=a,j=b;
    while(i<=b-1 && j <=c){
        if(arr[i]<=arr[j]){
            sorted[k] = arr[i];
            i++;
        }
        else{
            sorted[k] = arr[j];
            ans+=(b-i);
            j++;
        }
        k++;
    }
    while(i<=b-1){
        sorted[k] = arr[i];
        //ans+=(b-i);
        i++;
        k++;
    }
    while(j<=c){
        sorted[k] = arr[j];
        k++;
        j++;
    }
    k = 0;
    for(int i = a; i<=c; i++){
        arr[i] = sorted[k];
        k++;
    }
}
void merge_sort(int start,int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    merge_sort(start,mid);
    merge_sort(mid+1,end);
    merge(start,mid+1,end);
}

int main(){
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
    merge_sort(0,N-1);
    cout<<ans<<'\n';
}