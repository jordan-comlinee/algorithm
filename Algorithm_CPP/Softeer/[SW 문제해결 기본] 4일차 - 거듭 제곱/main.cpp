#include<bits/stdc++.h>
using namespace std;

int customPow(int N, int M) {
	if (M == 0) {
		return 1;
	}
	else {
		return N * customPow(N, M - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int t = 1; t <= 10; t++) {
		int T, N, M, result;
		cin >> T;
		cin >> N >> M;
		result = customPow(N, M);
		cout << "#" << T << " " << result << endl;
	}
}