#include<iostream>
#include<deque>

using namespace std;

int n,m;
int visited[201] = {0};

int assign(int cow, deque<int>* room,int* isFull){
    
    if(visited[cow]) return 0;
    visited[cow]= 1;
    
    for(int i= 0; i<(int)room[cow].size(); i++){
        int p = room[cow][i];
        
        if(isFull[p] == -1){
            isFull[p] = cow;
            return 1;
        }
        else{
            if(assign(isFull[p],room,isFull)==1){   //매칭 성공시
                isFull[p] = cow;
                return 1;
            }
            
        }
    }

    return 0;   //매칭 실패
}


int main(){
   
    cin>>n>>m;
    int cow[n];
    for(int i = 0; i<n; i++)
        cow[i] = i;
    deque<int> room[n];
    
    int isFull[m];
    
    for(int i = 0; i<m;i++){
        isFull[i] = -1;
    }
    
    int dem,input;
    
    for(int i = 0; i<n; i++){
        cin>>dem;
        for(int j = 0; j<dem; j++){
            cin>>input;
            room[i].push_back(input-1);
        }
    }
    int cnt = 0;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
        {
            visited[j] = 0;
        }
        cnt += assign(i,room,isFull);
    }
    
    cout<<cnt<<endl;
    //test
    /*
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<room[i].size(); j++)
        {
            cout<<room[i][j]<<" ";
        }
        cout<<endl;
    }
    */
}
