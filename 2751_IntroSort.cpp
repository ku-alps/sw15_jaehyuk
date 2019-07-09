//introsort
#include<iostream>
#include<cmath>

void swapData(int arr[], int n1, int n2){
    int temp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = temp;
}
void insertionSort(int* arr,int n){
    for(int i = 1; i<n; i++){
        int j = i;
        int temp = arr[i];
        while(j>=1){
            if(arr[j]<arr[j-1]){
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            j--;
        }
    }
}

void heapSort(int* arr,int left,int right){
    if(left >= right)
        return;
    
    int offset = left;
    
    for(int i = (right-left+1)/2; i>0; i--){
        int root = i;
        int k;
        
        while(root<(right-left+1)){//자식이 없을때까지
            k = 2*root;
            
            if(k<(right-left+1) && arr[offset+k-1]<arr[offset+k]){
                k++;
            }
            if(k<(right-left+1)+1 && arr[offset+root-1]<arr[offset+k-1]){
                swapData(arr,root+offset-1,k+offset-1);
            }
            root = k;
        }
    }
    
    for(int i = 1; i<=right-left+1; i++){
        swapData(arr,offset,offset+(right-left+1)-i);

        int root = 1;
        int k;
        
        //right-left+1-i가 이미정렬된 arr의 인덱스, 힙 상에서는 right-left+1-i+1
        while(root < right-left+1-i+1){
            k = 2*root;
            if(k<(right-left+1)-i && arr[offset+k-1]<arr[offset+k]){
                k++;
            }
            if(k<(right-left+1)-i+1 && arr[offset+root-1]<arr[offset+k-1]){
                swapData(arr,root+offset-1,k+offset-1);
            }
            root =k;
        }
    }
}
int getMid(int arr[],int a,int b,int c){
    if(arr[a]>arr[c])
    {
        if(arr[a]>arr[b]){
            if(arr[b]>arr[c]){
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
        if(arr[a]<arr[b]){
            if(arr[b]<arr[c]){
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
void introSort(int arr[],int left,int right,int depth){
    if(depth <= 0){
        //left - right 구간 heapsort
        heapSort(arr,left,right);
    }
    else{
        //quicksort
        int i = left,j = right;
        int npivot = getMid(arr,left,left+(right-left)/2,right);
        int pivot = arr[npivot];
        int flag = 0;
    
        if(i<j){
            do{
                if(j == npivot){
                    j--;
                    flag = 1;
                }
                
                if(arr[j]>pivot){
                    j--;
                }
                else if(arr[i]<=pivot&&i<j){
                    i++;
                }
                else{
                    swapData(arr,i,j);
                }
            }while(i<j);
            
            if(flag == 1)
                j++;
            
            swapData(arr,npivot,j);
            
            introSort(arr,left,j-1,depth-1);
            introSort(arr,j+1,right,depth-1);
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    std::cin>>n;
    int* arr = new int[n];
    
    int depth = 2*floor(log2(n));

    for(int i = 0; i<n; i++)
        std::cin>>arr[i];
    
    if(n<=16)
        insertionSort(arr,n);
    else
        introSort(arr,0,n-1,depth);
    
    for(int i = 0; i<n;i++)
        std::cout<<arr[i]<<'\n';
}
