/*
	BOJ17626
	https://www.acmicpc.net/problem/17626
	점화식 생각해내는 게 어렵다. 그리디하게 큰 수부터 빼려고 했는데, 반례가 너무 많더라, dp로 생각해서 최소인 지 하나씩 비교해야됐다.
	for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	}
	위 점화식에서 +1을 해주는 이유는, 그냥 간단히 j*j항이 추가로 붙으니까 해당 dp속 개수에서 하나 더해준 것이다.
*/
#include <bits/stdc++.h>
using namespace std;


int dp[50001];

int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);

	int N;
	cin >> N;

	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i] = i;

		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N];

	return 0;
}