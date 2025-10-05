/*

BFS ���� ����
queue�� 2�� �Ἥ ������ ��.
�ٵ� �����ϰ� �����ؾߵ�. �ʹ� ���� ���·� �����ߴ��� ���� �����ϸ� �ƴ� �� ������ �� ��.
unripens�� ����ؼ� ���� ������ �ϸ� �ƴµ�, 0�� -1�� �ѷ��ο��� ��Ȳ�� �ʹ� ��������.
�׸��� BFS���� ��ǥ �����ϴ� �� ������ ��. �� �� ����ؾߵ� ��.
https://www.acmicpc.net/problem/7576
*/
#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);

	int M, N;
	cin >> M >> N;
	vector<vector<int>>	Map(N, vector<int>(M));
	vector<vector<bool>> vis(N, vector<bool>(M));
	queue<pair<int, int>> Q_cur;


	int unripens = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 1) {
				vis[i][j] = true;
				Q_cur.push({ i,j });
			}
			else if (Map[i][j] == 0) {
				unripens++;
			}
			else {
				vis[i][j] = true;
			}
		}
	}
	int day = 0;
	stack<pair<int, int>> Q_next;
	while (!Q_cur.empty()) {
		pair<int, int> cur = Q_cur.front(); Q_cur.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (vis[nx][ny]) continue;
			unripens--;
			vis[nx][ny] = true;
			Q_next.push({ nx,ny });
		}


		if (Q_cur.empty()) {
			int nextlen = Q_next.size();
			for (int i = 0; i < nextlen; i++) {
				Q_cur.push(Q_next.top()); Q_next.pop();
			}
			day++;
			if (Q_cur.empty()) {
				day--;
			}
		}
	}
	if (!unripens)
	{
		cout << day;
	}
	else
		cout << -1;



	return 0;
}