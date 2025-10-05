
#include <bits/stdc++.h>
using namespace std;

//map�� ����ϴ� ���! vectoró�� ����ϴµ�, index�� �ش��ϴ� �� ���� ������ �� �ִ�.

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
