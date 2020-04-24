//포도주 시식
#include<iostream>
#include<algorithm>

using namespace std;

int result[10001];
int data[10001]={0};
int sat[10001] = {0};

int main(){
    int n;
    cin>>n;
    int k;
    for(int i = 0; i<n;i++){
        cin>>k;
        data[i] = k;
    }
    
    sat[1] = 1;
    
    int temp = 0;
    for(int i = 0; i<n; i++){
        if(i == 0)
        {
            result[i] = data[0];
        }
        else if(i == 1){
            result[i] = data[0]+data[1];
        }
        else if(i == 2){
            temp = max(max(data[0]+data[1],data[1]+data[2]),data[0]+data[2]);
            if(temp == data[1]+data[2])
                sat[i] = 1;
            result[i] = temp;
        }
        else{
            if(sat[i-1]!=1){
                temp = max(max(result[i-3]+data[i-1]+data[i],result[i-1]+data[i]),
                           result[i-2]+data[i]);
                if(temp == result[i-3]+data[i-1]+data[i])
                    sat[i] = 1;
                result[i] = temp;
            }else{
                temp = max(max(result[i-3]+data[i-1]+data[i],
                           result[i-2]+data[i]),result[i-1]);
                if(temp == result[i-3]+data[i-1]+data[i])
                    sat[i] = 1;
                result[i] = temp;
            }
        }
    }
    sort(&result[0],&result[n],greater<int>());
    cout<<result[0]<<endl;
    
}
