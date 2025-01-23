#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> wines, result;

void input_data() {
	cin >> n;
	wines.resize(n + 3);
	result.resize(n + 3);
	for (int i = 1; i < n+1; ++i) {
		cin >> wines[i];
	}
}

void solution() {
	result[1] = wines[1];
	result[2] = wines[1] + wines[2];
	for (int i = 3; i < n + 1; i++) {
		result[i] = max(max(result[i - 1], result[i - 2] + wines[i]), result[i - 3] + wines[i] + wines[i - 1]);
	}
	
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input_data();
	solution();
	cout << result[n] << endl;
	return 0;
}