#include<bits/stdc++.h>

using namespace std;
int N,M;
char board[11][11];
int visited[11][11][11][11][15] = {0};
//dir : 0,1,2,3
void swap(char (*arr)[11],int a, int b,int c,int d){
    char k = arr[a][b];
    arr[a][b] = arr[c][d];
    arr[c][d] = k;
}
pair<char(*)[11],int> goUp(char arr[11][11]){
    int cnt = 0;
    int isCor = 0;
    for(int j = 0; j<M; j++){
        for(int i = 0; i<N; i++){
            if(arr[i][j] == 'R' || arr[i][j] =='B'){
                int k = 1;
                while(i-k>=0&&((arr[i-k][j] != '#' && arr[i-k][j] != 'O') 
                && (arr[i-k][j] != 'R' && arr[i-k][j]!='B'))){
                    k++;
                }
                if(arr[i-k][j] == 'O'){
                    if(arr[i][j] == 'R'){
                        arr[i][j] = '.';
                        isCor = 1;
                        cnt++;
                    }
                    else{
                        return make_pair(arr,-1);
                    }
                }
                else{
                    //arr[i-k+2][j] = arr[i][j]; 
                    if(i-k+1>=0 && arr[i-k+1][j] == '.'){
                        swap(arr,i,j,i-k+1,j);
                        cnt++;
                    }
                }
            }
            
        }
    }
    if(isCor == 1){
        return make_pair(arr,1);
    }
    if(cnt == 0){
        return make_pair(arr,-1);
    }
    return make_pair(arr,0);
}
pair<char(*)[11],int> goRight(char arr[11][11]){
    int cnt = 0;
    int isCor = 0;
    for(int i = 0; i<N-1; i++){
        for(int j = M-1; j>=0; j--){
            if(arr[i][j] == 'R' || arr[i][j] =='B'){
                int k = 1;
                while(j+k<N-1&&((arr[i][j+k] != '#' && arr[i][j+k] != 'O') 
                && (arr[i][j+k] != 'R' && arr[i][j+k]!='B'))){
                    k++;
                }
                if(arr[i][j+k] == 'O'){
                    if(arr[i][j] == 'R'){
                        arr[i][j] = '.';
                        isCor = 1;
                        cnt++;
                    }
                    else{
                        return make_pair(arr,-1);
                    }
                }
                else{
                    //arr[i-k+2][j] = arr[i][j]; 
                    if(j+k-1<=M-1 && arr[i][j+k-1] == '.'){
                        swap(arr,i,j,i,j+k-1);
                        cnt++;
                    }
                }
            }
            
        }
    }
    if(isCor == 1){
        return make_pair(arr,1);
    }
    if(cnt == 0){
        return make_pair(arr,-1);
    }
    return make_pair(arr,0);
}
pair<char(*)[11],int> goDown(char arr[11][11]){
    int cnt = 0;
    int isCor = 0;
    for(int j = 0; j<M; j++){
        for(int i = N-1; i>=0; i--){
            if(arr[i][j] == 'R' || arr[i][j] =='B'){
                int k = 1;
                while(i+k<=N-1&&((arr[i+k][j] != '#' && arr[i+k][j] != 'O') 
                && (arr[i+k][j] != 'R' && arr[i+k][j]!='B'))){
                    k++;
                }
                if(arr[i+k][j] == 'O'){
                    if(arr[i][j] == 'R'){
                        arr[i][j] = '.';
                        isCor = 1;
                        cnt++;
                    }
                    else{
                        return make_pair(arr,-1);
                    }
                }
                else{
                    if(i+k-1<=N-1 && arr[i+k-1][j] == '.'){
                        swap(arr,i,j,i+k-1,j);
                        cnt++;
                    }
                }
            }
            
        }
    }
    if(isCor == 1){
        return make_pair(arr,1);
    }
    if(cnt == 0){
        return make_pair(arr,-1);
    }
    return make_pair(arr,0);
}
pair<char(*)[11],int> goLeft(char arr[11][11]){
    int cnt = 0;
    int isCor = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(arr[i][j] == 'R' || arr[i][j] =='B'){
                int k = 1;
                while(j-k>=0&&((arr[i][j-k] != '#' && arr[i][j-k] != 'O') 
                && (arr[i][j-k] != 'R' && arr[i][j-k]!='B'))){
                    k++;
                }
                if(arr[i][j-k] == 'O'){
                    if(arr[i][j] == 'R'){
                        arr[i][j] = '.';
                        isCor = 1;
                        cnt++;
                    }
                    else{
                        return make_pair(arr,-1);
                    }
                }
                else{
                    //arr[i-k+2][j] = arr[i][j]; 
                    if(j-k+1>=0 && arr[i][j-k+1] == '.'){
                        swap(arr,i,j,i,j-k+1);
                        cnt++;
                    }
                }
            }
            
        }
    }
    if(isCor == 1){
        return make_pair(arr,1);
    }
    if(cnt == 0){
        return make_pair(arr,-1);
    }else{
        return make_pair(arr,0);
    }
}
int bfs(){
    int cnt = 0;
    priority_queue<pair<int,pair<char(*)[11],int> >,vector<pair<int,pair<char(*)[11],int> > >,greater<pair<int,pair<char(*)[11],int> > > > que;
    que.push(make_pair(0,make_pair(board,0)));
    int res = 0;
    while(!que.empty()){
        cnt++;
        pair<int,pair<char(*)[11],int> > idx = que.top();
        
        char arr[11][11];
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                arr[i][j] = idx.second.first[i][j];
            }
        }
        int dist = idx.first+1;
        //cout<<dist<<endl;
        que.pop();

        int bx,by,rx,ry;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                if(arr[i][j] == 'R'){
                    rx = i,ry = j;
                }
                else if(arr[i][j] == 'B'){
                    bx = i,by = j;
                }
            }
        }
        if(visited[rx][ry][bx][by][dist] == 1){
            continue;
        }
        if(dist-1>=0 && visited[rx][ry][bx][by][dist] ==1){
            continue;
        }
        visited[rx][ry][bx][by][dist] = 1;


        char tup[11][11];
        char tright[11][11];
        char tdown[11][11];
        char tleft[11][11];
        
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                tup[i][j] = arr[i][j];
                tright[i][j] = arr[i][j];
                tdown[i][j] = arr[i][j];
                tleft[i][j] = arr[i][j];
            }
        }
        if(dist>12){
            res = -1;
            cout<<"cnt:"<<cnt<<endl;
            return res;
        }
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        pair<char(*)[11],int> tup1 = goUp(tup);
        char up[11][11];
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                up[i][j] = tup1.first[i][j];
            }
        }
        
        if(tup1.second == 1){
            res = dist;
            break;
        }
        else if(tup1.second == 0)
            que.push(make_pair(dist,make_pair(up,tup1.second)));

        pair<char(*)[11],int> tright1 = goRight(tright);
        char right[11][11];
        
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                right[i][j] = tright1.first[i][j];
            }
        }
        
        if(tright1.second == 1){
            res = dist;
            break;
        }
        else if(tright1.second == 0)
            que.push(make_pair(dist,make_pair(right,tright1.second)));

        pair<char(*)[11],int> tdown1 = goDown(tdown);
        char down[11][11];
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                down[i][j] = tdown1.first[i][j];
            }
        }
        
        if(tdown1.second == 1){
            res = dist;
            break;
        }
        else if(tdown1.second == 0){
            que.push(make_pair(dist,make_pair(down,tdown1.second)));
        }
        pair<char(*)[11],int> tleft1 = goLeft(tleft);
        char left[11][11];
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                left[i][j] = tleft1.first[i][j];
            }
        }
        if(tleft1.second == 1){
            res = dist;
            break;
        }
        else if(tleft1.second == 0)
            que.push(make_pair(dist,make_pair(left,tleft1.second)));
    }
    
    return res;    
}
int main(){
    cin>>N>>M;
    for(int i= 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
        }
    }
    char arr[11][11];
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            arr[i][j] = board[i][j];
        }
    }
    int ans = bfs();
    //pair<char(*)[11],int> ans = goLeft(arr);
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<ans.second<<endl;
    cout<<ans<<endl;
}