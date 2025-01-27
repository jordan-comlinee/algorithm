#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> coins;

void solution() {
	vector<int> result(k + 1, 0);
	result[0] = 1; // 0원을 만드는 방법은 1가지

	for (int i = 0; i < n; ++i) {
		for (int j = coins[i]; j <= k; ++j) {
			result[j] += result[j - coins[i]];
		}
	}
	cout << result[k] << endl;
}

void input_data() {
	cin >> n >> k;
	coins.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
	}
	sort(coins.begin(), coins.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input_data();
	solution();
}