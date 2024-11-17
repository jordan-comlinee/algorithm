#include <bits/stdc++.h>
using namespace std;

int T, N, P, result;

void solution() {
	for (int i = 1; i <= N; i++) {
		result += i;
		if (result == P){
			result--;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;

	for (int t = 0; t < T; t++){
		result = 0;
		cin >> N >> P;
		solution();
		cout << result << endl;
	}
}