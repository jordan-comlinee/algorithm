#include<bits/stdc++.h>
using namespace std;

int T, N, L, result = 0;
vector<pair<int, int>> ingredient;


void dfs(int index, int score, int kcal) {
	if (kcal > L) {
		return;
	}
	if (score > result) {
		result = score;
	}
	if (index == N) {
		return;
	}

	dfs(index + 1, score + ingredient[index].first, kcal + ingredient[index].second);
	dfs(index + 1, score, kcal);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> N >> L;
		ingredient = vector<pair<int, int>>(N);
		for (int n = 0; n < N; n++) {
			cin >> ingredient[n].first >> ingredient[n].second;
		}
		dfs(0, 0, 0);
		cout << "#" << t << " " << result << endl;
		ingredient.clear();
		result = 0;
	}
}