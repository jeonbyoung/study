/*
	BOJ2579
	https://www.acmicpc.net/problem/2579
	�׸� �׸��ϱ� �׳��� �ݹ� ���� ���� �� ����.
	�ܼ��� �����ϴ� �� �߿��� �� ����, Ȯ���� ��ȭ�� �� ¥�� �� �߿��� �� ����.
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