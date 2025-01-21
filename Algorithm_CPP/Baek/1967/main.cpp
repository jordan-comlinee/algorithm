#include<bits/stdc++.h>
using namespace std;

int N, maps= 0, farthestNode = 0;
map<int, vector<pair<int, int>>> nodes;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

void dfs(int start, int length, vector<bool>& visited) {
	visited[start] = true;
	if (length > maps){
		maps = length;
		farthestNode = start;
	}
	for (auto &neighbor : nodes[start]) {
		int next = neighbor.first;
		int weight = neighbor.second;
		if (!visited[next]) {
			dfs(next, length + weight, visited);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int n = 0; n < N-1; n++) {
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a].push_back(make_pair(b, c));
		nodes[b].push_back(make_pair(a, c));
	}
	vector<bool> visited(N + 1, false);
	dfs(1, 0, visited);
	fill(visited.begin(), visited.end(), false);
	maps = 0;
	dfs(farthestNode, 0, visited);
	cout << maps << endl;

}