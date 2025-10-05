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

	그냥 받자마자 해당 구간을 더하게 되면, 무조건 시간 초과남. 10만*10만이니 10억쯤 됨
	그러니까 받자마자 이전 것들이랑 더하고, 이후에 구간 입력받으면 시작부분 전이랑 빼면 됨.


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
			cout << num[J - 1] << '\n';
		else
			cout << num[J - 1] - num[I - 2] << '\n';

	}

	return 0;
}