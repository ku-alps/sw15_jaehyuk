//나이순 정렬(stable sort)
#include <iostream>
#include <vector>
using namespace std;

/*
void quicksort(vector<pair<int,string>>&arr,int left,int right){
    
    if(left<right){
    
        int pivot = arr[left].first;
        int i = left;
        int j = right;
    
        while(i<j){
            
            if(pivot < arr[j].first){
                j--;
            }
            else if(pivot > arr[i].first){
                i++;
            }
            
            else{   //인덱스 j보다 피벗이 크고, i보다 피벗이 작을때 swap
                if(arr[i].first == arr[j].first){
                    arr[i].swap(arr[j]);
                    j--;
                }
                else
                    arr[i].swap(arr[j]);
            }
        }
        arr[left].swap(arr[j]);
        
        quicksort(arr,left,j-1);
        quicksort(arr,j+1,right);
    }
}
 */
void merge(vector<pair<int,string>> &arr,vector<pair<int,string>> &sorted,int left,int mid, int right){
    int i,j,k,l;
    i = left;
    j = mid+1;
    k = left;
    
    while(i<=mid && j<=right){
        if(arr[i].first<=arr[j].first)
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }
    
    if(i>mid){
        for(l = j; l<=right; l++)
            sorted[k++] = arr[l];
    }
    else
        for(l = i; l<=mid; l++)
            sorted[k++] = arr[l];
    
    for(l = left; l<=right; l++){
        arr[l] = sorted[l];
    }
}
void mergesort(vector<pair<int,string>> &arr,vector<pair<int,string>> &sorted, int left, int right){
    int mid;
    
    if(left<right){
        mid = (left+right)/2;
        
        mergesort(arr,sorted,left,mid);
        mergesort(arr,sorted,mid+1,right);
        merge(arr,sorted,left,mid,right);
    }
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,string>> arr(n);
    vector<pair<int,string>> sorted(n);

    for(int i = 0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    //quicksort(arr,0,n-1);
    
    mergesort(arr,sorted,0,n-1);
    
    for(int i = 0; i<n; i++){
        cout<<arr[i].first<<" "<<arr[i].second<<'\n';
    }
}
