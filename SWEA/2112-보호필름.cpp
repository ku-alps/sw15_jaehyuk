#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int org[21][21] = {0,};
int arr[21][21] = {0,};
// vector<vector<int> > org;
// vector<vector<int> > arr;
int injcnt = 0;
int D,W,K;
int mmin;
void set_line(int idx){
    for(int i = 0; i<W; i++){
        arr[idx][i] = org[idx][i];
    }
    return;
}
void set_state(int idx, int chk){
    if(chk == -1) return;
    for(int i = 0; i<W; i++)
        arr[idx][i] = chk;
    return ;
}

bool chkInj(){
    int w = W;
    int d = D;
    for(int j = 0; j<w; j++){
        int temp = arr[0][j];
        int cnt = 1;
        int flag = 0;
        for(int i = 1; i<d; i++){
            if(temp == arr[i][j]){
                cnt++;
                flag = 0;
                if(cnt >= injcnt){
                    flag = 1;
                    break;
                    //통과한 층
                }
            }
            else{
                cnt = 1;
                flag = 0;
            }
            temp = arr[i][j];
        }
        if(flag == 0){
            return false;
        }
    }
    return true;
}
//idx번째 층을 A로 바꾸는 경우, B로 바꾸는 경우, 안바꾸는 경우
int dfs(int idx,int cnt){
    if(cnt>K){
        return 0;
    }
    //cout<<cnt<<endl;
    if(idx>=D){
        if(chkInj()==true){
            mmin = min(mmin,cnt);
        }
        return 0;
    }
    if(chkInj()==true){
        mmin = min(mmin,cnt);
        return 0;
    }
    //안바꿈
    dfs(idx+1,cnt);
    //A로 바꿈
    set_state(idx,0);
    dfs(idx+1,cnt+1);
    //B로 바꿈
    set_state(idx,1);
    dfs(idx+1,cnt+1);
    set_line(idx);
}

int main(){
    int T;
    cin>>T;
    for(int t = 1; t<=T; t++){
        int d,w,k;
        mmin = 999999999;
        cin>>d>>w>>k;
        injcnt = k;
        D=d,W=w,K=k;
        for(int i = 0; i<d; i++){
            for(int j = 0; j<w; j++){
                cin>>arr[i][j];
                org[i][j] = arr[i][j];
            }
        }
        if(k==1){ mmin = 0;}
        else{
            dfs(0,0);
        }
        cout<<"#"<<t<<" "<<mmin<<'\n';
        //층의 개수 선택
    }
}