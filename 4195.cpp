#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>

using namespace std;
int F,tc;
int mmax = 0;
int idx = 1;
int* frd;
map<string,int> arr;

int find(int idx){
    if(frd[idx]<0)
        return idx;
    frd[idx] = find(frd[idx]);
    return frd[idx];
}
void merge(int a,int b){
    a = find(a);
    b = find(b);
    
    if(a==b){

        printf("%d\n",(-1)*frd[a]);
        return;
    }
    else if(frd[a] <= frd[b]){
        frd[a] += frd[b];
        frd[b] = a;
        printf("%d\n",(-1)*frd[a]);
    }
    else if(frd[b] < frd[a]){
        frd[b] += frd[a];
        frd[a] = b;
        printf("%d\n",(-1)*frd[b]);
    }
    
    
}
int main(){
   
    scanf("%d",&tc);
    for(int i = 0; i<tc; i++){
        idx = 1;
        mmax = 0;
        scanf("%d",&F);
        frd = new int[F*2+1];
        for(int j = 1; j<=F*2; j++){
            frd[j] = -1;
        }
        arr.clear();
        
        for(int j = 0; j<F; j++){
            char name1[21];
            char name2[21];
            scanf("%s %s",name1,name2);
            
            if(arr.count(name1) == 0){
                arr[name1] = idx;
                idx++;
            }
            if(arr.count(name2) == 0){
                arr[name2] = idx;
                idx++;
            }
            merge(arr[name1],arr[name2]);
        }
    }
}
