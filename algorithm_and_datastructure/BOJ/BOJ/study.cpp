
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> tree(100001);
vector<bool> vis(100001);

int main() {
	ios::sync_with_stdio(0);cin.tie(0);

	int V;
	cin >> V;

	for (int i = 1; i <= V; i++) {
		int vertex, weight;
		cin >> vertex >> weight;
		if (vertex == -1)
			break;
		tree[i].push_back({ vertex, weight });
	}
	
	vector<int> candidates;
	for (int i = 1; i <= V; i++) {
		if (tree[i].size() == 1) {
			candidates.push_back(i);
		}
	}

	vector<int> whosthebest;
	for (int i = 0; i < candidates.size(); i++) {
		stack<vector<pair<int, int>>> S;
		vis.assign(V + 1, false);
		int sum = 0;

		S.push(tree[candidates[i]]);
		vis[candidates[i]] = true;
		while (!S.empty()) {
			vector<pair<int, int>> cur = S.top(); S.pop();
			for (int j = 0; j < cur.size(); j++) {
				if (vis[cur[j].first])
					continue;
				else {
					S.push(tree[cur[j].first]);

				}
					
					
			}
		}


	}


	return 0;
}