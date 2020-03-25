#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first > b.first)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> arr;
    vector<pair<int, int>> penalty;
    vector<int> dot;
    arr.resize(N);
    penalty.resize(N - 1);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N - 1; i++)
    {
        penalty[i] = make_pair(arr[i + 1] - arr[i], i);
    }
    sort(penalty.begin(), penalty.end(), cmp);

    if (K == 1)
    {
        cout << arr[N - 1] - arr[0] << '\n';
        return 0;
    }
    else if (K == N)
    {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < K - 1; i++)
        dot.push_back(penalty[i].second);
    sort(dot.begin(), dot.end());
    int ans = 0;

    for (int i = 0; i < dot.size() - 1; i++)
    {
        ans += arr[dot[i + 1]] - arr[dot[i] + 1];
    }
    if (dot.size() >= 1)
        ans += (arr[dot[0]] - arr[0]) + (arr[N - 1] - arr[dot[dot.size() - 1] + 1]);

    cout << ans << '\n';
}
