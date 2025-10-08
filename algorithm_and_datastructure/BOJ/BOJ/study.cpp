/*
	BOJ1043
	https://www.acmicpc.net/problem/1043
	재밌는 문제였다. 풀이는 두 가지다. 주석으로 달아놓은 것은 처음 생각한 BFS를 이용해서 하나씩 순회하는 형식으로 문제를 풀었다.
	일반적으로는 다르게 풀어서 그것도 공부해서 본문에 올렸다.
	Union-Find(분리 집합)이라는 것에서 나온 아이디어인데, find_root가 중요했다. 결국 원래 값으로 찾아오게 돼있으니, 서로 연결된 형태를 구현해낼 수 있었다.
*/

#include <bits/stdc++.h>
using namespace std;

int find_root(int a, vector<int>& vec) {
	if (vec[a] == a)
		return a;
	else {
		return vec[a] = find_root(vec[a], vec);
	}
}

void unite(int a, int b, vector<int>& vec) {
	int rootA = find_root(a, vec);
	int rootB = find_root(b, vec);
	if (rootA != rootB) {
		vec[rootB] = rootA;
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> identifier(N + 1);
	iota(identifier.begin(), identifier.end(), 0);

	int numofTknow, Tknow;
	vector<int> whoknows;
	cin >> numofTknow;
	for (int i = 0; i < numofTknow; i++) {
		cin >> Tknow;
		whoknows.push_back(Tknow);
	}


	vector<vector<int>> party(M);
	for (int i = 0; i < M; i++) {
		int numofp;
		cin >> numofp;
		int firstman;
		cin >> firstman;
		party[i].push_back(firstman);
		for (int j = 1; j < numofp; j++) {
			int secondman;
			cin >> secondman;
			party[i].push_back(secondman);
			unite(firstman, secondman, identifier);
		}
	}
	vector<bool> primeofT(N + 1,false);
	for (int person : whoknows) {
		primeofT[find_root(person, identifier)] = true;
	}


	int numofsafes = 0;
	for (int i = 0; i < M; i++) {
		if (party[i].empty()) {
			numofsafes++;
			continue;
		}
		int prime = find_root(party[i][0], identifier);
		if (!primeofT[prime])
			numofsafes++;
	}

	cout << numofsafes;


	return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;


bool isblack[51];
vector<int> person_info[51];
vector<int> party_info[51];

int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);

	int N, M;
	cin >> N >> M;

	int bnum, num;
	cin >> bnum;

	queue<int> blacklist;

	for (int i = 0; i < bnum; i++) {
		cin >> num;
		blacklist.push(num);
		isblack[num] = true;
	}

	for (int i = 0; i < M; i++) {
		int numpeople;
		cin >> numpeople;
		for (int j = 0; j < numpeople; j++) {
			int num;
			cin >> num;
			party_info[i].push_back(num);
			person_info[num].push_back(i);
		}
	}
	while (!blacklist.empty()) {
		int prob = blacklist.front(); blacklist.pop();

		for (int party_idx : person_info[prob]) {
			for (int person_idx : party_info[party_idx]) {
				if (!isblack[person_idx]) {
					isblack[person_idx] = true;
					blacklist.push(person_idx);
				}
			}
		}
	}

	int numofsafe = 0;
	for (int i = 0; i < M;i++) {
		bool safe = true;
		for (int person : party_info[i]) {
			if (isblack[person]) {
				safe = false;
				break;
			}
		}
		if (safe)
			numofsafe++;
	}

	cout << numofsafe;



	return 0;
}


*/