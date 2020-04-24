#include<iostream>
using namespace std;

int blue = 0;
int white = 0;

void makePaper(int** arr,int x,int y,int n){
    if(n == 1){
        if(arr[x][y] == 1)
            blue++;
        else
            white++;
        
        return;
    }
    
    int sum = 0;
    
    for(int i = x; i<x+n; i++)
        for(int j = y; j<y+n;j++){
            sum+= arr[i][j];
        }
    
    if(sum == n*n){
        blue += 1;
        return;
    }
    else if(sum == 0){
        white += 1;
        return;
    }
    
    int midX = (2*x+n)/2;
    int midY = (2*y+n)/2;
    
    makePaper(arr, x, y, n/2);
    makePaper(arr, midX, midY, n/2);
    makePaper(arr, midX, y, n/2);
    makePaper(arr, x, midY, n/2);
}

int main(){
    int n;
    cin>>n;
    int** arr = new int*[n];
    for(int i = 0; i<n;i++){
        arr[i] = new int[n];
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    
    makePaper(arr,0,0,n);
    
    cout<<white<<endl<<blue<<endl;
}
