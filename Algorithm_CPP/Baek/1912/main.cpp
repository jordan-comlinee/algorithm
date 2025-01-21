#include <bits/stdc++.h>
using namespace std;

int N, maps;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<int> numbers(N);
	vector<int> dp(N);
	for (int n = 0; n < N; n++){
		cin >> numbers[n];
	}
	dp[0] = numbers[0];
	maps = numbers[0];
	for (int i = 1; i < N; i++){
		dp[i] = max(dp[i - 1] + numbers[i], numbers[i]);
		maps = max(dp[i], maps);
	}
	cout << maps << endl;

}