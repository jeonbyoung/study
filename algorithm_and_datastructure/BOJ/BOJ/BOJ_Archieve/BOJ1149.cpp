/*
	BOJ1149
	https://www.acmicpc.net/problem/1149
	그전에 풀던 dp와 다른 점은 dp로 푸는 열이 3개로 늘어났다는 점이다. 신기하당.
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1001][3];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;
	vector<vector<int>> home_info(N, vector<int>(3));
	for (int i = 0; i < N; i++) {
		int r, g, b;

		cin >> r >> g >> b;
		home_info[i][0] = r;
		home_info[i][1] = g;
		home_info[i][2] = b;
	}

	dp[0][0] = home_info[0][0];
	dp[0][1] = home_info[0][1];
	dp[0][2] = home_info[0][2];

	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + home_info[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + home_info[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + home_info[i][2];
	}

	int min = dp[N - 1][0];
	for (int i = 1; i < 3; i++) {
		if (min > dp[N - 1][i]) {
			min = dp[N - 1][i];
		}
	}

	cout << min;


	return 0;
}