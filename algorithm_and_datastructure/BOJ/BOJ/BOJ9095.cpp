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
		//각 3개의 이전 것들의 경우들에게 각각 1,2,3씩 맨 왼쪽에 더해준다고 생각하면 경우가 맞아떨어짐.
	}

	for (int i = 0; i < n; i++) {
		cin >> t;
		cout << arr[t] << '\n';
	}

	return 0;
}