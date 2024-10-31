#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int N, M;
bool visited[21][21] = { false };
int board[21][21];
vector<pair<int, int>> friends;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int result = 0;

void bfs() {
	while (!friends.empty()) {
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	friends.resize(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> friends[i].first >> friends[i].second;
	}
	bfs();
}