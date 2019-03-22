#include<iostream>
using namespace std;

int man[50][2];
int dungchi[50];

int main(){
    int n;
    cin>>n;
    int x,y;
    for(int i = 0; i<n;i++){
        cin>>x>>y;
        man[i][0] = x;
        man[i][1] = y;
    }
    
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            if(man[i][0]>man[j][0] && man[i][1]>man[j][1])
                dungchi[i]++;
            else if(man[i][0]>=man[j][0] || man[i][1]>=man[j][1]){
                //dungchi[i]++;
            }
        }
    }
    int maxdungchi = 0;
    for(int i = 0; i<n;i++){
        if(maxdungchi < dungchi[i])
            maxdungchi = dungchi[i];
    }
    for(int i = 0; i<n;i++){
        cout<<(-1)*dungchi[i]+maxdungchi+1<<endl;
    }
}

