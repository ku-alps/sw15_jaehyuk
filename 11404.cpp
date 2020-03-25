#include<iostream>

using namespace std;

int arr[100][100];

int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;
    int from,to,weight;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i == j)
                arr[i][j] = 0;
            else
                arr[i][j] = 200000000;
        }
    }
    
    for(int i = 0; i<m;i++)
    {
        cin>>from>>to>>weight;
        if(arr[from-1][to-1] > weight)
            arr[from-1][to-1] = weight;
    }
    
    for(int k = 0; k<n; k++)
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(arr[i][j] > arr[i][k]+arr[k][j])
                    arr[i][j] = arr[i][k]+arr[k][j];
            }
        }
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n;j++)
        {
            if(arr[i][j]>=200000000)
                arr[i][j] = 0;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
