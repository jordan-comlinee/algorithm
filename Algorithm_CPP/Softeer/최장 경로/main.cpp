#include <bits/stdc++.h>
using namespace std;

int result = 0;
map<int, vector<int>> nodes;

void dfs(int start, vector<bool> visited, int cnt) {
	visited[start] = true;
	for (int next : nodes[start]) {
		if (!visited[next]) {
			dfs(next, visited, cnt + 1);
		}
	}
	if (result < cnt){
		result = cnt;
		return;
	}
}

// node 연결 검증
void printNode(map<int, vector<int>> nodes) {
	for (const auto& pair : nodes) {
		int key = pair.first;
		const vector<int>& neighbors = pair.second;
		cout << key << ": ";
		for (int neighbor : neighbors) {
			cout << neighbor << " ";
		}
		cout << endl;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int N, M;
		cin >> N >> M;
		vector<bool> visited(N+1, false);
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			nodes[a].push_back(b);
			nodes[b].push_back(a);
		}
		for (int n = 1; n <= N; n++) {
			dfs(n, visited, 1);
			fill(visited.begin(), visited.end(), false);
		}
		cout << "#" << t << " " << result << endl;
		nodes.clear();
		result = 0;
	}
}