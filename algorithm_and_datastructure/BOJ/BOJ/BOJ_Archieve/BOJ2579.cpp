/*
	BOJ2579
	https://www.acmicpc.net/problem/2579
	그림 그리니까 그나마 금방 생각 나는 것 같다.
	단순히 생각하는 게 중요한 것 같고, 확실히 점화식 잘 짜는 게 중요한 것 같다.
*/
#include <bits/stdc++.h>
using namespace std;


int dp[301];

int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);

	int fs;
	cin >> fs;
	vector<int> f_info(fs + 1);
	for (int i = 1; i <= fs; i++) {
		cin >> f_info[i];
	}

	dp[1] = f_info[1], dp[2] = f_info[1] + f_info[2], dp[3] = max(f_info[1] + f_info[3], f_info[2] + f_info[3]);
	for (int i = 4; i <= fs; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + f_info[i - 1]) + f_info[i];
	}

	cout << dp[fs];

	return 0;
}