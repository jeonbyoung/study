/*
	2차원 matrix 토마토랑 똑같다.
	다만 차원을 3d tensor로 올린 것 뿐이였다.
	https://www.acmicpc.net/problem/7569

*/
#include <bits/stdc++.h>
using namespace std;

int dh[6] = { 0,0,0,0,1,-1 };
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };


int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);

	int M, N, H;
	cin >> M >> N >> H;
	vector<vector<vector<int>>>	Map(H, vector<vector<int>>(N, vector<int>(M)));

	vector<vector<vector<int>>>	vis(H, vector<vector<int>>(N, vector<int>(M)));
	queue<tuple<int, int, int>> Q_cur;


	int unripens = 0;

	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> Map[h][i][j];
				if (Map[h][i][j] == 1) {
					vis[h][i][j] = true;
					Q_cur.push({ h,i,j });
				}
				else if (Map[h][i][j] == 0) {
					unripens++;
				}
				else {
					vis[h][i][j] = true;
				}
			}
		}
	}
	int day = 0;
	stack<tuple<int, int, int>> Q_next;
	while (!Q_cur.empty()) {
		tuple<int, int, int> cur = Q_cur.front(); Q_cur.pop();

		for (int i = 0; i < 6; i++) {
			int nh = get<0>(cur) + dh[i];
			int nx = get<1>(cur) + dx[i];
			int ny = get<2>(cur) + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nh < 0 || nh >= H) continue;
			if (vis[nh][nx][ny]) continue;
			unripens--;
			vis[nh][nx][ny] = true;
			Q_next.push({ nh,nx,ny });
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