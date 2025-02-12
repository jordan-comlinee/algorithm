#include<bits/stdc++.h>
using namespace std;

int N, T, P;
const int MAX = 16;
vector<pair<int, int>> time_table(MAX);
vector<int> result_table(MAX);

void input_data();
void solution();

int main() {
	input_data();
	solution();
	cout << result_table[0] << endl;
}

void input_data() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> T >> P;
		time_table[i] = make_pair(T, P);
	}
}

void solution() {
	for (int i = N - 1; i >= 0; --i) {
		int next_day = i + time_table[i].first;
		if (next_day <= N) {
			result_table[i] = max(time_table[i].second + result_table[next_day], result_table[i + 1]);
		}
		else {
			result_table[i] = result_table[i + 1];
		}
	}
}