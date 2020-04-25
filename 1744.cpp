#include<bits/stdc++.h>
using namespace std;
int arr[10001];
int main(){
    int N;
    cin>>N;
    for(int i  = 0; i<N; i++)
        cin>>arr[i];
    sort(arr,arr+N);
    int sum = 0;
    int leftend = 0;
    for(int i = 0; i<N; i++){
        if(i == N-1&&arr[i]<=0){
            sum+=arr[i];
            leftend = i+1;
            break;
        }
        else if(arr[i]>=0){
            leftend = i;
            break;
        }

        if(arr[i]<0 && arr[i+1]<0){
            sum+=arr[i]*arr[i+1];
            i++;
            if(i>N-1){
                leftend = N;
                break;
            }
        }
        else if(arr[i]<0 && arr[i+1]==0){
            sum+=arr[i]*arr[i+1];
            leftend = i+2;
            break;
        }
        else if(arr[i]==0 && arr[i+1] == 0){
            leftend = i+1;
            break;
        }
        else if(arr[i]<0 && arr[i+1] >0){
            sum+=arr[i];
            leftend = i+1;
            break;
        }
    }
    for(int i = N-1; i>=leftend; i--){
        if(i==leftend){
            sum+= arr[i];
            break;
        }

        if(arr[i] == 1){
            sum+= arr[i];
            continue;
        }
        else if(arr[i-1] == 1){
            sum+= arr[i];
            continue;
        }

        if(arr[i]>0&&arr[i-1]>0){
            sum+=arr[i]*arr[i-1];
            i--;
        }
        else if(arr[i]>0&&arr[i-1] == 0){
            sum+=arr[i];
            break;
        }
        else if(arr[i]>0&&arr[i-1]<0){
            sum+=arr[i];
            break;
        }
        else{
            break;
        }
    }
    cout<<sum;
}