//피벗 개선 퀵소트 (stable, iterative, deque)
#include<iostream>
#include<deque>

using namespace std;

int getMid(int a,int b,int c){
    if(a>c)
    {
        if(a>b){
            if(b>c){
                return b;
            }
            else{
                return c;
                
            }
        }
        else{
            return a;
        }
    }
    
    //c가 a보다 큼
    else
    {
        if(a<b){
            if(b<c){
                return b;
            }
            else{
                return c;
            }
        }
        else{
            return a;
        }
    }
}
void IquickSort(deque<int>& arr,int n){
    
    int left,right;
    deque<int> stk;
    deque<int> less;
    deque<int> greater;
    
    stk.push_back(n-1);
    stk.push_back(0);
    
    while(!stk.empty()){
        
        left = stk.back();  // 0
        stk.pop_back();
        right = stk.back(); // n-1
        stk.pop_back();
        
        if(left<right){
            
            int pivot = getMid(arr[left],arr[(left+right)/2],arr[right]);
            int i;
            for(i = left; i<arr.size(); i++){
                
                if(arr[i]<pivot)
                    less.push_back(arr[i]);
                   
                else if(arr[i]>pivot)
                    greater.push_back(arr[i]);
                  
            }
            arr.erase(arr.end()-((int)less.size()+(int)greater.size()+1),arr.end());
            arr.insert(arr.end(), less.begin(),less.end());
            arr.push_back(pivot);
            arr.insert(arr.end(), greater.begin(),greater.end());
            
            stk.push_back(left+(int)less.size()-1);
            stk.push_back(left);
            stk.push_back(right);
            stk.push_back(left+(int)less.size()+1);
            
            less.clear();
            greater.clear();
        }
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n;cin>>n;
    deque<int> arr(n);
    
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    IquickSort(arr,n);
    
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<'\n';
}
