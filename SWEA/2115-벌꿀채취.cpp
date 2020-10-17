#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int N,M,C;
int arr[11][11] = {0,};

struct honey{
    int x;
    int y;
    int v;
};
vector<honey> vec;

int mmax = 0;
bool cmp(honey &h1, honey &h2){
    if(h1.v<h2.v){
        return true;
    }
    return false;
}
void dfs(int x,int y,int max_y,int r,int sum){
    if(y>=max_y){
        honey h;
        h.x = x;
        h.y = y;
        h.v = sum;
        vec.push_back(h);
        //mmax = max(mmax,sum);
        return;
    }
    if(y>=N){
        honey h;
        h.x = x;
        h.y = y;
        h.v = sum;
        vec.push_back(h);
        //mmax = max(mmax,sum);
        return;
    }
    if(r>=arr[x][y]){
        //현재것을 선택
        dfs(x,y+1,max_y,r-arr[x][y],sum+pow(arr[x][y],2));
    }
    //현재것을 선택X
    dfs(x,y+1,max_y,r,sum);
}

int main(){
    int T;cin>>T;
    for(int t = 1; t<=T; t++){
        cin>>N>>M>>C;
        vec.clear();
        mmax = 0;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                cin>>arr[i][j];
            }
        }
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                int sum = 0;
                dfs(i,j,j+M,C,0);
            }
        }
        //sort(vec.begin(),vec.end(),cmp);
        for(int i = 0; i<vec.size()-1; i++){
            for(int j = i+1; j<vec.size(); j++){
                if(vec[i].x!=vec[j].x){
                    mmax = max(mmax,vec[i].v+vec[j].v);
                }
                else{
                    if(vec[i].y+M>vec[j].y && vec[i].y<=vec[j].y){
                        continue;
                    }
                    if(vec[j].y+M>vec[i].y && vec[j].y<=vec[i].y){
                        continue;
                    }
                    mmax = max(mmax,vec[i].v+vec[j].v);
                }
            }
        }
        // for(int i = 0; i<vec.size(); i++){
        //     cout<<vec[i].x<<" "<<vec[i].v<<endl;
        // }
        cout<<"#"<<t<<" "<<mmax<<'\n';
    }
}