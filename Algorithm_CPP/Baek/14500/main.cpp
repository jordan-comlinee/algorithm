#include <bits/stdc++.h>
using namespace std;

int N, M, result, maxValue = 0;
int board[501][501] = { 0 };
bool visited[501][501] = { false };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int n, int m , int depth, int hap) {
	if (hap + (3 - depth) * maxValue <= result) return;
	if (depth == 3) {
		result = max(result, hap);
	}
	for (int i = 0; i < 4; i++) {
		int nx = n + dx[i];
		int ny = m + dy[i];
		if ( 0 <= nx && nx < N && 0 <= ny && ny < M && !visited[nx][ny]){
			visited[nx][ny] = true;
			dfs(nx, ny, depth + 1, hap+board[nx][ny]);
			visited[nx][ny] = false;
		}
	}
}

void checkOtherShape(int n, int m) {
	int shapes[4][4][2] = {
		{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
		{{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
		{{0, 0}, {1, 0}, {2, 0}, {1, 1}},
		{{0, 0}, {1, 0}, {2, 0}, {1, -1}}
	};
	for (int i = 0; i < 4; i++) {
		int sum = 0;
		bool valid = true;
		for (int j = 0; j < 4; j++) {
			int nx = n + shapes[i][j][0];
			int ny = m + shapes[i][j][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				valid = false;
				break;
			}
			sum += board[nx][ny];
		}
		if (valid){
			result = max(result, sum);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> board[n][m];
			maxValue = max(maxValue, board[n][m]);
		}
	}
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			visited[n][m] = true;
			dfs(n, m, 0, board[n][m]);
			visited[n][m] = false;
			checkOtherShape(n, m);
		}
	}
	cout << result << endl;
}