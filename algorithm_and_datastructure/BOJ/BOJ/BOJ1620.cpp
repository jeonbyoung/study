
#include <bits/stdc++.h>
using namespace std;

//map을 사용하는 방법! vector처럼 사용하는데, index에 해당하는 걸 내가 정해줄 수 있는.

int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);

	int  N, M;
	cin >> N >> M;
	vector<string> dogam;
	map<string, int> nton;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		dogam.push_back(name);
		nton[name] = i+1;
	}
	for (int i = 0; i < M; i++) {
		string q;
		cin >> q;
		if ((q[0] - '0') > 0 && (q[0] - '0') <= 9) {
			cout << dogam[stoi(q)-1]<<'\n';
		}
		else {
			cout << nton[q] << '\n';
		}
	}

	return 0;
}
