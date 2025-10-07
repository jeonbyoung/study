/*
	BOJ17626
	https://www.acmicpc.net/problem/17626
	��ȭ�� �����س��� �� ��ƴ�. �׸����ϰ� ū ������ ������ �ߴµ�, �ݷʰ� �ʹ� ������, dp�� �����ؼ� �ּ��� �� �ϳ��� ���ؾߵƴ�.
	for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	}
	�� ��ȭ�Ŀ��� +1�� ���ִ� ������, �׳� ������ j*j���� �߰��� �����ϱ� �ش� dp�� �������� �ϳ� ������ ���̴�.
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