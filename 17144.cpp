#include<bits/stdc++.h>

using namespace std;

int main(){
    int R,C,T;cin>>R>>C>>T;
    int arr[51][51]={0};
    int diff[51][51]={0};
    vector<int> cleaner;
    for(int i = 0 ; i<R; i++){
        for(int j = 0; j<C; j++){
            cin>>arr[i][j];
            if(arr[i][j] == -1){
                cleaner.push_back(i);
            }
        }
    }
    while(T--){

    for(int i = 0 ; i<R; i++){
        for(int j = 0; j<C; j++){
            if(arr[i][j] >= 1){
                int diffusion = arr[i][j]/5;
                if(i-1>=0){
                    if(arr[i-1][j] == -1){
                        //arr[i][j]-=diffusion;
                    }
                    else{
                        arr[i][j]-=diffusion;
                        diff[i-1][j] += diffusion;    
                    }
                }
                if(i+1<=R-1){
                    if(arr[i+1][j] == -1){
                        //arr[i][j] -= diffusion;
                    }
                    else{
                        arr[i][j] -= diffusion;
                        diff[i+1][j] += diffusion;
                    }
                }
                if(j-1>=0){
                    if(arr[i][j-1] == -1){
                        //arr[i][j] -=diffusion;
                    }
                    else{
                        arr[i][j] -= diffusion;
                        diff[i][j-1] += diffusion;
                    }
                }
                if(j+1<=C-1){
                    if(arr[i][j+1] == -1){
                        //arr[i][j] -=diffusion;
                    }
                    else{
                        arr[i][j] -= diffusion;
                        diff[i][j+1] += diffusion;
                    }
                }
            }
        }
    }
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            arr[i][j] += diff[i][j];
            diff[i][j] = 0;
        }
    }
    //cleaner
    for(int i = cleaner[0]-1; i>=0; i--){
        arr[i][0] = arr[i-1][0];
    }
    for(int i = 0; i<C-1; i++){
        arr[0][i] = arr[0][i+1];
    }
    for(int i = 0; i<cleaner[0]; i++){
        arr[i][C-1] = arr[i+1][C-1];
    }
    for(int i = C-1; i> 0; i--){
        arr[cleaner[0]][i] = arr[cleaner[0]][i-1];
        if(arr[cleaner[0]][i] == -1){
            arr[cleaner[0]][i] = 0;
        }
    }

    for(int i = cleaner[1]+1; i<R; i++){
        arr[i][0] = arr[i+1][0];
    }
    for(int i = 0; i<C-1; i++){
        arr[R-1][i] = arr[R-1][i+1];
    }
    for(int i = R-1; i>cleaner[1]; i--){
        arr[i][C-1] = arr[i-1][C-1];
    }
    for(int i = C-1; i> 0; i--){
        arr[cleaner[1]][i] = arr[cleaner[1]][i-1];
        if(arr[cleaner[1]][i] == -1){
            arr[cleaner[1]][i] = 0;
        }
    }

    }
    /*
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int sum = 0;
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(arr[i][j]!= -1){
                sum+=arr[i][j];
            }
        }
    }
    cout<<sum;
}