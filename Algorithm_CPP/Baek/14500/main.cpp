#include <bits/stdc++.h>
using namespace std;

int N, M, result;
int board[501][501] = { 0 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void findMax(int n, int m) {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> board[n][m];
		}
	}
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			findMax(n, m);
		}
	}
}