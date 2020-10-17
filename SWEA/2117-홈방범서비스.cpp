#include<iostream>
#include<vector>

using namespace std;
int N,M;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int arr[21][21] = {0,};
pair<int,int> search(int x,int y,int k){
    int sum = 0;
    int cost = (k+1)*(k+1)+(k)*(k);
    
    if(arr[x][y] == 1){
        sum+=1;
    }
    for(int i = 1; i<=k; i++){
        int lefty = y-i;
        int leftx = x;
        while(lefty<y){
            if(lefty>=0 && lefty<N && leftx<N && leftx>=0){
                if(arr[leftx][lefty] == 1){
                    sum+=1;
                }
            }
            lefty++;
            leftx--;
        }
        int upy = y;
        int upx = x-i;
        while(upx<x){
            if(upx>=0 && upx<N && upy<N && upy>=0){
                if(arr[upx][upy]==1){
                    sum+=1;
                }
            }
            upx++;
            upy++;
        }
        int righty = y+i;
        int rightx = x;
        while(righty>y){
            if(righty >=0&&righty<N&&rightx<N&&rightx>=0){
                if(arr[rightx][righty] == 1){
                    sum+=1;
                }
            }
            righty--;
            rightx++;
        }
        int downy = y;
        int downx = x+i;
        while(downx>x){
            if(downx>=0&&downy>=0&&downx<N&&downy<N){
                if(arr[downx][downy] == 1){
                    sum+=1;
                }
            }
            downx--;
            downy--;
        }
    }
    return make_pair(sum*M-cost,sum);
}
int main(){
    int T;cin>>T;
    for(int t = 1; t<=T; t++){
        int mmax = 0;
        cin>>N>>M;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                cin>>arr[i][j];
            }
        }
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                for(int k = 0; k<2*N; k++){
                    pair<int,int> p = search(i,j,k);
                    if(p.first>=0 && mmax<=p.second){
                        mmax = p.second;
                    }
                }
            }
        }
        cout<<"#"<<t<<" "<<mmax<<'\n';
    }
}