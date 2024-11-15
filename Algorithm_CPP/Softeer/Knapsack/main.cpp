#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, K, V, C;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		vector<vector<int>> knapsack(N + 1, vector<int>(K + 1, 0));
		vector<pair<int, int>> solution;
		for (int n = 0; n < N; n++) {
			cin >> V >> C;
			solution.push_back(make_pair(V, C));
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++) {
				int curWeight = solution[i - 1].first;
				int curValue = solution[i - 1].second;
				if (curWeight <= j) {
					knapsack[i][j] = max(knapsack[i - 1][j - curWeight] + curValue, knapsack[i - 1][j]);
				}
				else {
					knapsack[i][j] = knapsack[i - 1][j];
				}
			}
		}
		cout << "#"<< t << " " << knapsack[N][K] << endl;
	}
}