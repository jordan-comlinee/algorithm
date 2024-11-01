#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int N, M;
bool visited[21][21] = { false };
int board[21][21];
int fx, fy;
vector<pair<int, int>> friends;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<int> result;

bool isAvailable(int x, int y) {
	return (0 <= x && x < N && 0 <= y && y < N && !visited[x][y]);
}

void dfs(int cnt, int apples) {
	if (cnt == 4) {
		result.push_back(apples);
		return;
	}
	int size = friends.size();
	cout << "====" << endl;
	for (int i = 0; i < size; i++) {
		int x = friends.front().first;
		int y = friends.front().second;
		friends.pop_back();
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			cout << nx << " " << ny << endl;
			if (isAvailable(nx, ny)) {
				int newApples = apples + board[nx][ny];
				friends.push_back(make_pair(nx, ny));
				visited[nx][ny] = false;
				cout << newApples << endl;
				dfs(cnt + 1, newApples);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int apple = 0;
	cin >> N >> M;
	friends.resize(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	for (int j = 0; j < M; j++) {
		cin >> fx >> fy;
		friends.push_back(make_pair(fx-1, fy-1));
		apple += board[fx-1][fy-1];
		visited[fx-1][fy-1] = true;
	}
	for (int i = 0; i < M; i++) {
		cin >> friends[i].first >> friends[i].second;
	}
	bfs();
}