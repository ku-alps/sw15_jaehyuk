#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> arr;
vector<vector<int>> dp;
int main()
{
    int N, M;
    cin >> N >> M;
    arr.resize(N + 1);
    dp.resize(N + 1);
    for (int i = 0; i < N; i++)
    {
        arr[i].resize(M + 1);
        dp[i].resize(M + 1);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    for (int i = 1; i < N; i++)
        dp[i][0] = dp[i - 1][0] + arr[i][0];
    for (int i = 1; i < M; i++)
        dp[0][i] = dp[0][i - 1] + arr[0][i];
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
        }
    }
    /*
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */
    int K;
    cin >> K;
    int a, b, c, d;
    for (int i = 0; i < K; i++)
    {
        cin >> a >> b >> c >> d;
        if (a >= 2)
        {
            if (b >= 2)
            {
                cout << dp[c - 1][d - 1] - dp[a - 2][d - 1] - dp[c - 1][b - 2] + dp[a - 2][b - 2] << '\n';
            }
            else
            {
                cout << dp[c - 1][d - 1] - dp[a - 2][d - 1] << '\n';
            }
        }
        else
        {
            if (b >= 2)
            {
                cout << dp[c - 1][d - 1] - dp[c - 1][b - 2] << '\n';
            }
            else
            {
                cout << dp[c - 1][d - 1] << '\n';
            }
        }
    }
}
