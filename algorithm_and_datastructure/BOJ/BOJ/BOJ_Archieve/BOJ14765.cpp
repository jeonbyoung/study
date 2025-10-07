/*
	BOJ14754
	https://www.acmicpc.net/problem/14754
	��ȸ �غ��ϸ� ���� ������ �� �ô� ����. ���� ��ü�� �°� �����ߴ�.
	�ٸ� sum�� type�� long long���� �ٲ�ߵȴٴ� ������ �� �ߴ�.
	��������.

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