#include <bits/stdc++.h>
using namespace std;

int arr[11];

int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);

	int n, t;
	cin >> n;
	arr[1] = 1, arr[2] = 2, arr[3] = 4, arr[4] = 7;
	for (int i = 5; i < 11; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		//�� 3���� ���� �͵��� ���鿡�� ���� 1,2,3�� �� ���ʿ� �����شٰ� �����ϸ� ��찡 �¾ƶ�����.
	}

	for (int i = 0; i < n; i++) {
		cin >> t;
		cout << arr[t] << '\n';
	}

	return 0;
}