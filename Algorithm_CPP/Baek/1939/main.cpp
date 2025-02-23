#include <bits/stdc++.h>
using namespace std;
#define MAX_VALUE 1000000000

// N개의 섬, M개의 다리
int N, M;
// A번 섬과 B번 섬 사이 중량 제한이 C인 다리
int A, B, C;
// 시작점, 끝점, 결과
int st, en, result = 0;
vector<vector<pair<int,int>>> island;

void inputData();
void solution();

int main() {
	inputData();
	solution();
	cout << result << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	island.resize(N + 1);
	for (int i = 0; i < M; ++i) {
		cin >> A >> B >> C;
		island[A].push_back(make_pair(B, C));
		island[B].push_back(make_pair(A, C));
	}
	cin >> st >> en;
}

void solution() {
	priority_queue<pair<int, int>> q;
	vector<int> visited(N + 1, false);
	q.push(make_pair(MAX_VALUE, st));

	while (!q.empty()) {
		int minDistance = q.top().first;
		int currentNode = q.top().second;
		q.pop();
		if (currentNode == en) {
			result = max(result, minDistance );
		}
		if (visited[currentNode]) continue;
		visited[currentNode] = true;

		for (auto next : island[currentNode]) {
			int nextNode = next.first;
			int dist = next.second;

			if (!visited[next.first]) {
				q.push(make_pair(min(dist, minDistance), nextNode));
			}
		}
	}

}