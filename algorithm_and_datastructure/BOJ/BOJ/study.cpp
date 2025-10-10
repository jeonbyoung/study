/*
	BOJ11053
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1000];

int main() {
	int length;
	cin >> length;
	int* arr = new int[length];

	for (int i = 0; i < length; i++) {
		cin >> arr[i];
	}

	dp[0] = 1;
	for (int i = 1; i < length; i++) {
		vector<int> collections;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				collections.push_back(dp[j]);
			}
		}
		if (!collections.empty()) {
			auto it = max_element(collections.begin(), collections.end());
			dp[i] = *it + 1;
		}
		else {
			dp[i] = 1;
		}
	}
	int max = 0;
	for (int i = 0; i < length;i++) {
		if (dp[i] > max)
			max = dp[i];
	}

	cout << max;


	delete[] arr;

	return 0;
}