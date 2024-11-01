#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int N, M;
pair<int, int> out, namwoo = make_pair(0, 0);
vector<pair<int, int>> ghost;
vector<string> maze;
bool escapable = false;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visited[1000][1000] = { false };


void isEscapable() {
	if (escapable) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

void check(char n, int i, int j) {
	if (n == 'D') {
		out = make_pair(i, j);
	}
	else if (n == 'N') {
		namwoo = make_pair(i, j);
	}
	else if (n == 'G') {
		ghost.push_back(make_pair(i, j));
	}
}

bool isInRange(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < M && (maze[x][y] == '.' || maze[x][y] == 'D') && !visited[x][y]) {
		return true;
	}
	else {
		return false;
	}
}

void dfs(int x, int y) {
	if (x == out.first && y == out.second) {
		escapable = true;
		return;
	}

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isInRange(nx, ny)) {
			dfs(nx, ny);
			if (escapable) return; // 이미 탈출 가능성을 확인하면 더 이상 탐색하지 않음
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	maze.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> maze[i];
		for (int j = 0; j < M; j++) {
			check(maze[i][j], i, j);
		}
	}
	dfs(namwoo.first, namwoo.second);
	isEscapable();
}
