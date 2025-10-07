/*
	BOJ1654
	https://www.acmicpc.net/problem/1654
	로직은 생각해냈는데, 종료 조건을 다는 것이 어려웠다. 숫자가 서로 가까울 경우에 대해서
	생각하는 것이 힘들었는데, inf가 sup을 넘어갈 정도로 가까워진 순간에 이것이 종료됨을 알게 됐다.
*/
#include <bits/stdc++.h>
using namespace std;



int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);

	int K, N;
	cin >> K >> N;
	vector<int> noflan(K);
	for (int i = 0; i < K; i++) {
		cin >> noflan[i];
	}

	sort(noflan.begin(), noflan.end(), greater<int>());
	long long sup = noflan[0];
	long long inf = 1;
	long long  mid = (sup + inf) / 2;

	while (inf < sup) {
		mid = inf + (sup - inf) / 2;
		if (mid == 0) mid = 1;
		long long sum = 0;
		for (int i = 0; i < K; i++) {
			sum += noflan[i] / mid;
		}
		if (sum < N) {
			sup = mid - 1;
		}
		else { //primary
			inf = mid + 1;
		}
		//cout << mid << "\n";
	}

	cout << sup;


	return 0;
}