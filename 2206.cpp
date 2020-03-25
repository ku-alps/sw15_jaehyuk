#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
vector<vector<char> > arr;
vector<vector<int> > visited;
queue<pair<int, pair<int, int> > > que;
int main()
{
    cin >> N >> M;
    arr.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 0; i < N + 1; i++)
    {
        arr[i].resize(M + 1);
        visited[i].resize(M + 1);
    }
    for (int i = 0; i < N + 1; i++)
    {
        fill(visited[i].begin(), visited[i].end(), 0);
    }
    string input;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = input[j];
        }
    }

    int dist = 10000;
    int dist_count = 0;
    for (int j = 0; j < N + 1; j++)
    {
        fill(visited[j].begin(), visited[j].end(), 0);
    }
    que.push(make_pair(0, make_pair(0, 0)));
    
    while (!que.empty())
    {
        pair<int, pair<int, int> > idx = que.front();

        int stk = idx.first;
        int r = idx.second.first;
        int c = idx.second.second;
        que.pop();
        //cout<<r<<" "<<c<<endl;

        if(visited[r][c] == 1){
            continue;
        }
        visited[r][c] = 1;

        if (r == N - 1 && c == M - 1)
        {
            if (dist_count - 1 < dist)
                dist = dist_count - 1;
            break;
        }
        if (r + 1 < N && visited[r + 1][c] == 0 && arr[r + 1][c] == '0')
        {
            if(arr[r+1][c] == '0'){
                que.push(make_pair(stk,make_pair(r+1, c )));
            }
            else if(arr[r+1][c] == '1'&&stk==0){
                que.push(make_pair(1,make_pair(r+1, c )));
            }
        }
        if (c + 1 < M && visited[r][c + 1] == 0)
        {
            if(arr[r][c+1] == '0'){
                que.push(make_pair(stk,make_pair(r, c+1 )));
            }
            else if(arr[r][c+1] == '1'&&stk==0){
                que.push(make_pair(1,make_pair(r, c+1 )));
            }
        }
        if (r - 1 >= 0 && visited[r - 1][c] == 0)
        {
            if(arr[r-1][c] == '0'){
                que.push(make_pair(stk,make_pair(r-1, c )));
            }
            else if(arr[r-1][c] == '1'&&stk==0){
                que.push(make_pair(1,make_pair(r-1, c )));
            }
        }
        if (c - 1 >= 0 && visited[r][c - 1] == 0)
        {
            if(arr[r][c - 1] == '0'){
                que.push(make_pair(stk,make_pair(r, c - 1)));
            }
            else if(arr[r][c-1] == '1' && stk==0){
                que.push(make_pair(1,make_pair(r, c - 1)));
            }
            //visited[r][c - 1] = 1;
        }
        
        dist_count++;
    }
    if(dist == 10000){
        cout<<"-1";
    }
    else{
        cout<<dist-1;
    }
}