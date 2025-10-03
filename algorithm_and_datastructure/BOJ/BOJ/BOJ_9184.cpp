
/*
dp 문제 푸는 감
초기 값 잡고, 규칙성 찾은 담에, table 만들어서 다시 그 값 안 찾게 하는 식으로 가면 될 듯.
나중에 글 쓰는 걸로!

*/
/*
#include <bits/stdc++.h>
using namespace std;

int w_tensor[21][21][21] = {};

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}
	else if (w_tensor[a][b][c] != 0) {
		return w_tensor[a][b][c];
	}
	else if (a < b && b < c) {
		w_tensor[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		w_tensor[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}

	return w_tensor[a][b][c];
}

int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		cout << w(a, b, c) << '\n';
	}

	return 0;
}
*/