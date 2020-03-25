#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > arr;
vector<vector<int> > visited;
int main()
{
    int N, M;
    cin >> N >> M;
    int r, c, d;
    cin >> r >> c >> d;

    arr.resize(N);
    visited.resize(N);
    for (int i = 0; i < N; i++)
    {
        visited[i].resize(M);
        fill(visited[i].begin(), visited[i].end(), 0);
        arr[i].resize(M);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                visited[i][j] = 1;
        }
    }
    int stuck = 0;
    int res = 0;
    int k = 0;
    while (true)
    {
        k++;
        if(arr[r][c] == 0){
            arr[r][c] = 2;
            visited[r][c] = 1;
            res ++;
        }
        if (d == 0)
        {
            if (c - 1 >= 0 && arr[r][c - 1] == 0)
            {
                c = c - 1;
                stuck = 0;
                d = 3;
            }
            else
            {
                d = 3;
                stuck++;
            }
        }
        else if (d == 1 && arr[r - 1][c] == 0)
        {
            if (r - 1 >= 0)
            {
                
                r = r - 1;
                stuck = 0;
                d--;
            }
            else
            {
                d--;
                stuck++;
            }
        }
        else if (d == 2 && arr[r][c + 1] ==0)
        {
            if (c + 1 <= M - 1)
            {
                
                c = c + 1;
                stuck = 0;
                d--;
            }
            else
            {
                d--;
                stuck++;
            }
        }
        else if (d == 3 && arr[r + 1][c] == 0)
        {
            if (r + 1 <= N - 1)
            {
                
                r = r + 1;
                stuck = 0;
                d--;
            }
            else
            {
                d--;
                stuck++;
            }
        }
        if (((r + 1 < N && visited[r + 1][c] == 1) || r + 1 == N) 
        && ((c + 1 < M && visited[r][c + 1] == 1) || c + 1 == M) 
        && ((r - 1 >= 0 && visited[r - 1][c] == 1) || r - 1 == -1) 
        && ((c - 1 >= 0 && visited[r][c - 1] == 1) || c - 1 == -1))
        {
            if (d == 0)
            {
                if (r + 1 < N && arr[r + 1][c] == 1)
                {
                    break;
                }
                else if (r + 1 == N)
                {
                    break;
                }
                else
                {
                    r++;
                }
            }
            else if (d == 1)
            {
                if (c - 1 >= 0 && arr[r][c - 1] == 1)
                {
                    break;
                }
                else if (c - 1 == -1)
                {
                    break;
                }
                else
                {
                    c--;
                }
            }
            else if (d == 2)
            {
                if (r - 1 >= 0 && arr[r - 1][c] == 1)
                {
                    break;
                }
                else if (r - 1 == -1)
                {
                    break;
                }
                else
                {
                    r--;
                }
            }
            else
            {
                if (c + 1 < M && arr[r][c + 1] == 1)
                {
                    break;
                }
                else if (c + 1 == M)
                {
                    break;
                }
                else
                {
                    c++;
                }
            }
        }
        cout<<r<<" "<<c<<'\n';
    }
    cout<<res<<endl;
}