#include<iostream>
#include<algorithm>
using namespace std;
int N;
int p[15];
int t[15];
int dp[15] = { 0 ,};	//idx일까지 얻을 수 있는 최대 이익
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t[i] >> p[i];
	}
	dp[0] = 0;
	dp[t[0] - 1] = p[0];
	for (int i = 1; i < N; i+ㅁ+) {
		dp[i] = max(dp[i],dp[i - 1]);
		if (i + t[i] - 1 > N-1) continue;
		dp[i + t[i] - 1] = max(dp[i + t[i] - 1], p[i] + dp[i - 1]);
	}
	cout << dp[N - 1];
}