#include <bits/stdc++.h>
using namespace std;

// 테스트 케이스의 개수, 지원자의 숫자
int T, N, a, b, result;
vector<pair<int, int>> score;
vector<pair<int, int>> interview;


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
		score.resize(N);
		interview.resize(N);
		for (int n = 0; n < N; ++n) {
			cin >> a >> b;
			score[n] = make_pair(a, b);
			interview[n] = make_pair(b, a);
		}
		sort(score.begin(), score.end());
		sort(interview.begin(), interview.end());
		solution();
		cout << result << endl;
	}
	return;
}
void solution() {
	set<pair<int, int>> passed;
	passed.insert(score[0]);
	passed.insert(make_pair(interview[0].second, interview[0].first));
	pair<int, int> standard = make_pair(interview[0].second, score[0].second);
	//cout << endl;
	//cout << standard.first << " " << standard.second << endl;
	for (auto sc : score) {
		if (standard.first < sc.first || standard.second < sc.second) continue;
		cout << sc.first << " " << sc.second << endl;
		passed.insert(sc);
	}
	cout << endl;
	
	result = passed.size();
	//cout << passed.size() << endl;
	return;
}