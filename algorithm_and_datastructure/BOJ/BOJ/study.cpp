/*
	1
	1 +2 
	1+2+3
	1+2+3+4

	1
	2
	3
	4

	2 4
	1 3

*/
#include <bits/stdc++.h>
using namespace std;


int main(void) {
	std::ios::sync_with_stdio(false), std::cin.tie(0);

	int N, M, n, I, J;
	vector<int> num;
	int input;
	long long sum = 0;;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		sum += input;
		num.push_back(sum);
	}
	

	for (int i = 0; i < M; i++) {
		cin >> I >> J;
		if (I == 1)
			cout << num[J - 1]<<'\n';
		else
			cout << num[J - 1] - num[I - 2] << '\n';
			
	}

	return 0;
}