#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> _size(3);
vector<int> isEnable(201,0);
struct obj{
    int cup[3];
};
queue<obj> chkque;

int que[201][201][201] = {0};
int k = 0;

int dfs(vector<int> &water,int from, int to){
    //cout<<"bef"<<water[0]<<" "<<water[1]<<" "<<water[2]<<endl;
    
    if(water[to]+water[from] > _size[to]){
        water[from] = water[from] - (_size[to] - water[to]);
        water[to] = _size[to];
    }
    else{
        water[to] += water[from];
        water[from] = 0;
    }
    
    if(water[0] == 0){
        isEnable[water[2]] = 1;
    }
    
    if(que[water[0]][water[1]][water[2]] == 1)
        return 0;
    que[water[0]][water[1]][water[2]] = 1;

    //cout<<"aft"<<water[0]<<" "<<water[1]<<" "<<water[2]<<endl;
    
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(i == j || (i==from && j == to) || water[i] == 0||(i==to && j==from)||water[j]==_size[j]){
                continue;
            }
            dfs(water,i,j);
        }
    }
    return 0;
}
int main(){
    cin>>_size[0]>>_size[1]>>_size[2];
    isEnable[_size[2]] = 1;
    vector<int> cup(3);
    cup[0] = 0,cup[1] = 0,cup[2] = _size[2];
    obj temp;
    temp.cup[0] = 0,temp.cup[1] = 0,temp.cup[2] = _size[2];
    chkque.push(temp);

    while(!chkque.empty()){
        obj idx = chkque.front();
        chkque.pop();
        if(idx.cup[0] == 0){
            isEnable[idx.cup[2]] = 1;
        }
        if(que[idx.cup[0]][idx.cup[1]][idx.cup[2]]==0)
            que[idx.cup[0]][idx.cup[1]][idx.cup[2]]=1;
        else
            continue;

        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(i != j){
                    int storage[3];
                    storage[0] = idx.cup[0];
                    storage[1] = idx.cup[1];
                    storage[2] = idx.cup[2];
                    if(idx.cup[i]+idx.cup[j]>_size[i]){
                        storage[j] = idx.cup[j] - (_size[i] - idx.cup[i]);
                        storage[i] = _size[i];
                    }
                    else{
                        storage[i] += idx.cup[j];
                        storage[j] = 0;
                    }
                    obj stor;
                    stor.cup[0] = storage[0];
                    stor.cup[1] = storage[1];
                    stor.cup[2] = storage[2];

                    chkque.push(stor);
                }
            }
        }
    }

    /*
    dfs(cup,2,0);

    for(int i= 0; i<201; i++){
        for(int j = 0; j<201; j++){
            for(int k = 0; k<201; k++)
                que[i][j][k] = 0;
        }
    }
    que[0][0][_size[2]] = 1;
    cup[0] = 0,cup[1] = 0,cup[2] = _size[2];
    dfs(cup,2,1);
    */

    for(int i = 0; i<201; i++){
        if(isEnable[i] == 1){
            cout<<i<<" ";
        }
    }
}