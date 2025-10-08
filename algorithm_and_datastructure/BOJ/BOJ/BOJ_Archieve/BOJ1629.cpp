/*
	BOJ1629
	https://www.acmicpc.net/problem/1629
	재귀를 생각 못 했다. 단순 숫자 계산이라도 2억번인 것도 유념하지 못 했고, 곱하다 보면 맞물리는 때가 있겠다 싶었는데,
	안일했다. a^b를 구하는 것이므로, b가 짝수이면 b -> b/2 + b/2로, b가 홀수이면 b-1 +1의 경우로 보고, 트리 형태의 구조를 짤 수 있겠다.
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