#include<iostream>

using namespace std;

int data[1004] = {0};
int cache[1004] = {0};

void BS(int* arr, int left,int right,int key){
    while(left<right){
        int mid = (left+right)/2;
        
        if(key < arr[mid])
            left = mid+1;
        else if(key > arr[mid])
            right = mid-1;
        else
            return;
    }
    if(key>=arr[left])
        arr[left] = key;
    else
        arr[left+1] = key;
}
void BSrecur(int* arr,int left,int right,int key){
    if(left >= right)
        arr[left] = key;
    
    int mid = (left+right)/2;
    
    if(key < arr[mid])
        BSrecur(arr,mid+1,right,key);
    else if(key > arr[mid])
        BSrecur(arr,left,mid-1,key);
    else
        return;
}
int main(){
    int n;
    cin>>n;
    int a;
    
    for(int i = 0 ; i<n; i++){
        cin>>a;
        data[i] = a;
    }
    cache[0] = data[0];
    int index = 0;
    for(int i = 1; i<n; i++){
        if(cache[index] > data[i]){
            cache[index+1] = data[i];
            index++;
        }
        else if(cache[index] < data[i]){
            BS(cache, 0, index, data[i]);
            //BSrecur(cache, 0, index, data[i]);
        }
    }
    cout<<index+1<<endl;
}
