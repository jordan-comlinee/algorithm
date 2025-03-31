#include <bits/stdc++.h>
using namespace std;

// 테스트 케이스의 개수, 지원자의 숫자
int T, N, a, b, result;
vector<int> score;


void inputData();
void solution();

int main() {
	inputData();
	solution();
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N;
		score.resize(N+1);
		//interview.resize(N);
		for (int n = 0; n < N; ++n) {
			cin >> a >> b;
			score[a] = b;
		}
		solution();
		cout << result << endl;
	}
	return;
}
void solution() {
	result = 0;
	int highest = INT32_MAX;

	for (int i = 1; i <= N; ++i) {
		if (highest > score[i]) result++;
		highest = min(highest, score[i]);
	}
	return;
}