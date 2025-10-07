/*
	BOJ14754
	https://www.acmicpc.net/problem/14754
	대회 준비하며 같이 연습할 때 봤던 문제. 로직 자체는 맞게 생각했다.
	다만 sum의 type을 long long으로 바꿔야된다는 생각을 못 했다.
	유념하자.

*/
#include <bits/stdc++.h>
using namespace std;


int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);

	int M, N;
	cin >> M >> N;
	vector<vector<int>> box(M, vector<int>(N));
	vector<vector<int>> box_remain(M, vector<int>(N));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cin >> box[i][j];
	}

	for (int i = 0; i < M; i++) {
		int max = 0;
		for (int j = 0; j < N; j++) {
			if (max < box[i][j]) {
				max = box[i][j];
			}
		}
		for (int j = 0; j < N; j++) {
			if (max == box[i][j]) {
				box_remain[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int max = 0;
		for (int j = 0; j < M; j++) {
			if (max < box[j][i]) {
				max = box[j][i];
			}
		}
		for (int j = 0; j < M; j++) {
			if (max == box[j][i]) {
				box_remain[j][i] = 1;
			}
		}

	}

	long long sum = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			if (box_remain[i][j] == 0) {
				sum += box[i][j];
			}
	}

	cout << sum;

	return 0;
}