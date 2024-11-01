#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, cnt = 0;
vector<pair<int, int>> dest;
int board[5][5]{ 0 };
bool visited[5][5]{ false };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void printBoard() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void printDest() {
	for (int i = 0; i < dest.size(); i++) {
		cout << dest[i].first << " " << dest[i].second << endl;
	}
}

void dfs(pair<int, int> start, int idx) {
	if (idx == m) {
		cnt += 1;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = start.first + dx[i];
		int ny = start.second + dy[i];
		if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
		if (!visited[nx][ny] && board[nx][ny] == 0) {
			visited[nx][ny] = true;
			if (nx == dest[idx].first && ny == dest[idx].second) {
				dfs(dest[idx], idx + 1);
			}
			else {
				dfs(make_pair(nx, ny), idx);
			}
			visited[nx][ny] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		dest.push_back(make_pair(x, y));
	}
	visited[dest[0].first][dest[0].second] = true;
	dfs(dest[0], 1);
	cout << cnt << endl;
}