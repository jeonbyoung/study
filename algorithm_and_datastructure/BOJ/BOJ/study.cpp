#include <bits/stdc++.h>
using namespace std;

using graph = vector<vector<int>>;

int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	
	int N, M, start;
	cin >> N >> M >> start;

	graph G(N+1);
	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		G[from].push_back(to);
		G[to].push_back(from);
	}

	//DFS
	stack<pair<int, vector<int>>> s;
	vector<bool> svis(N+1);
	svis[start] = true;
	s.push({ start,G[start] });
	while (!s.empty()) {
		pair<int,vector<int>> curpos = s.top(); s.pop();
		int curv = curpos.first;
		vector<int> cur = curpos.second;
		if (svis[curv]&&start!=curv)
			continue;
		svis[curv] = true;
		std::cout << curv << " ";
		sort(cur.begin(), cur.end(),greater<int>());
		for (int i = 0; i < cur.size(); i++) {
			int moveto = cur[i];
			if (svis[moveto]) {
				continue;
			}
			else {
				
				s.push({ moveto,G[moveto] });
			}
		}
	}
	std::cout << '\n';

	//BFS
	queue<pair<int, vector<int>>> q;
	vector<bool> vis(N + 1);
	vis[start] = true;
	//std::cout << start << " ";
	q.push({ start,G[start] });
	while (!q.empty()) {
		pair<int, vector<int>> curpos = q.front(); q.pop();
		int curv = curpos.first;
		vector<int> cur = curpos.second;
		if (vis[curv] && start != curv)
			continue;
		vis[curv] = true;
		std::cout << curv << " ";
		sort(cur.begin(), cur.end());
		for (int i = 0; i < cur.size(); i++) {
			int moveto = cur[i];
			if (vis[moveto]) {
				continue;
			}
			else {

				q.push({ moveto,G[moveto] });
			}
		}
	}
	std::cout << '\n';



	return 0;
}