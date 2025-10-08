/*
	BOJ1629
	https://www.acmicpc.net/problem/1629
	��͸� ���� �� �ߴ�. �ܼ� ���� ����̶� 2����� �͵� �������� �� �߰�, ���ϴ� ���� �¹����� ���� �ְڴ� �;��µ�,
	�����ߴ�. a^b�� ���ϴ� ���̹Ƿ�, b�� ¦���̸� b -> b/2 + b/2��, b�� Ȧ���̸� b-1 +1�� ���� ����, Ʈ�� ������ ������ © �� �ְڴ�.
*/
#include <bits/stdc++.h>
using namespace std;


long long solve(long long a, long long b, long long c) {

	if (b == 1) {
		return a % c;
	}

	long long result = solve(a, b / 2, c);

	result = (result * result) % c;

	if (b % 2 == 1) {
		result = (result * a) % c;
	}

	return result;
}


int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;

	cout << solve(a, b, c);

	return 0;
}