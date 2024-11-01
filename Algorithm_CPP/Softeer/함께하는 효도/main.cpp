#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int N, M;
bool visited[21][21] = { false };
int board[21][21];
<<<<<<< HEAD
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
=======
vector<pair<int, int>> friends;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int result = 0;

void bfs() {
	while (!friends.empty()) {
>>>>>>> b41cce27ceb67237a4cac4b5433e8d20af125376
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
<<<<<<< HEAD
	int apple = 0;
	cin >> N >> M;
=======
	cin >> N >> M;
	friends.resize(M);
>>>>>>> b41cce27ceb67237a4cac4b5433e8d20af125376
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
<<<<<<< HEAD
	for (int j = 0; j < M; j++) {
		cin >> fx >> fy;
		friends.push_back(make_pair(fx-1, fy-1));
		apple += board[fx-1][fy-1];
		visited[fx-1][fy-1] = true;
	}

	dfs
=======
	for (int i = 0; i < M; i++) {
		cin >> friends[i].first >> friends[i].second;
	}
	bfs();
>>>>>>> b41cce27ceb67237a4cac4b5433e8d20af125376
}