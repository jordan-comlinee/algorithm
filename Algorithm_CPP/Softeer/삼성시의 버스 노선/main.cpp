#include <bits/stdc++.h>
using namespace std;

int T, N, A, B, P, C;
int result[5001];

void solution(vector<pair<int, int>>& busRoute) {
	for (pair<int, int> r : busRoute){
		for (int i = r.first; i <= r.second; i++) {
			result[i]++;
		}
	}
}

void printResult(vector<int> busStop) {
	for (int i : busStop){
		cout << result[i] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		vector<int> busStop;
		vector<pair<int, int>> busRoute;
		cin >> N;
		for (int n = 0; n < N; n++){
			cin >> A >> B;
			busRoute.push_back(make_pair(A, B));
		}
		cin >> P;
		for (int p = 0; p < P; p++)
		{
			cin >> C;
			busStop.push_back(C);
		}
		solution(busRoute);
		cout << "#" << t << " ";
		printResult(busStop);
		memset(result, 0, sizeof(result));
	}
}