/*
	BOJ1654
	https://www.acmicpc.net/problem/1654
	������ �����س´µ�, ���� ������ �ٴ� ���� �������. ���ڰ� ���� ����� ��쿡 ���ؼ�
	�����ϴ� ���� ������µ�, inf�� sup�� �Ѿ ������ ������� ������ �̰��� ������� �˰� �ƴ�.
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