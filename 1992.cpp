//쿼드트리
#include <iostream>
using namespace std;

int g_arr[66][66];

void quadtree(int x1,int x2,int y1,int y2){
    //초기값 : 1,8,1,8
    
    int sum = 0;
    
    for(int i = x1; i<=x2; i++){
        for(int j = y1; j<=y2; j++){
            sum += g_arr[i][j];
        }
    }

    //cout<<"sum = "<<sum<<endl;
    if(x1 == x2 || y1 == y2)
    {
        cout<<g_arr[x1][y1];
        return;
    }
    if(!(sum == 0 || sum == 1*(x2-x1+1)*(y2-y1+1))){
        cout<<"(";
        
        quadtree(x1,(x1+x2-1)/2,y1,(y1+y2-1)/2);    //2사분면
        quadtree(x1,(x1+x2-1)/2,(y1+y2-1)/2+1,y2);    //3사분면
        quadtree((x1+x2-1)/2+1,x2,y1,(y2+y1-1)/2);    //1사분면
        quadtree((x1+x2-1)/2+1,x2,(y1+y2-1)/2+1,y2);    //4사분면
        
        cout<<")";
    }
    
    else if(sum == 0){
        //cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
        cout<<"0";
    }
    else if(sum == 1*(x2-x1+1)*(y2-y1+1)){
        cout<<"1";
    }
    else{
        cout<<"Find the bug!"<<endl;
    }
    return;
}

int main(){
    int n;
    cin>>n;
    char** arr = new char*[n];
    
    for(int i = 0; i<n;i++)
        arr[i] = new char[n];
    
    char temp[n];
    
    for(int i = 1; i<=n; i++){
        cin>>temp;
        for(int j = 0; j<n;j++){
            g_arr[i][j+1] = temp[j]-48;
        }
    }
    /*
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n;j++){
            cout<<g_arr[i][j];
        }
        cout<<endl;
    }*/
    quadtree(1,n,1,n);
}
