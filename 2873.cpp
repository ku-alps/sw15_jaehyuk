#include<bits/stdc++.h>

using namespace std;

int arr[1001][1001];

int main(){
    int R,C;
    cin>>R>>C;

    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cin>>arr[i][j];
        }
    }
    
    if(R%2 == 1){
        for(int i = 1; i<C; i++){
            cout<<"R";
        }
        for(int j = 1; j<R; j++){
            if(j%2 == 0){
                cout<<"D";
                for(int i = 1; i<C; i++)
                    cout<<"R";
            }else{
                cout<<"D";
                for(int i = 1; i<C; i++){
                    cout<<"L";
                }
            }
        }
    }
    
    else if(C%2 == 1){
        for(int i = 1; i<C; i++){
            cout<<"D";
        }
        for(int j = 1; j<C; j++){
            if(j%2 == 0){
                cout<<"R";
                for(int i = 1; i<C; i++)
                    cout<<"U";
            }else{
                cout<<"R";
                for(int i = 1; i<C; i++){
                    cout<<"D";
                }
            }
        }
        
    }
}