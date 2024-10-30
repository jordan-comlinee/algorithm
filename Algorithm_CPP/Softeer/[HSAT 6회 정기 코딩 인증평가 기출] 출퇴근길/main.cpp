#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int N, M, S, T, cnt = 0;
vector<vector<int>> nodeList(N + 1);
vector<bool> visited1, visited2;

bool dfs(int n, int t, vector<bool>& visited) {
	if (n != t && !nodeList[n].size()) return false;
	bool flag = false;
	for (int neighbor : nodeList[n]) {
		if (neighbor == t || visited[neighbor])
		{
			flag = true;
			continue;
		}
		visited[neighbor] = true;
		if (!dfs(neighbor, t, visited)) {
			visited[neighbor] = false;
		}
		else
		{
			flag = true;
		}
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	nodeList.resize(N + 1);
	visited1.resize(N + 1, false);
	visited2.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		nodeList[x].push_back(y);
	}
	cin >> S >> T;
	dfs(S, T, visited1);
	dfs(T, S, visited2);

	for (int i = 1; i <= N; i++) {
		if (visited1[i] && visited2[i] && i!=S && i!=T){
			cnt++;
		}
	}
	cout << cnt;

}