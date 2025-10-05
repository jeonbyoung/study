/*

BFS 쓰는 문제
queue를 2개 써서 돌리면 됨.
근데 간단하게 생각해야됨. 너무 꼬인 상태로 생각했더니 쉽게 생각하면 됐던 것 같은데 안 됨.
unripens를 사용해서 숫자 덧셈만 하면 됐는데, 0이 -1로 둘러싸여진 상황만 너무 몰두했음.
그리고 BFS에서 좌표 지정하는 게 서투른 듯. 좀 더 고민해야될 듯.
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