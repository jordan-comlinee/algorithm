#include <bits/stdc++.h>
using namespace std;

const int MAX = 300;
int N, M, R;
int board[MAX][MAX];
int tmpBoard[MAX][MAX];

void inputData();
void rotate(int l);
void solution();
void printData();

int main() {
	inputData();
	solution();
	printData();
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> R;
	for (int n = 0; n < N; ++n) {
		for (int m = 0; m < M; ++m) {
			cin >> board[n][m];
		}
	}
}

void rotate(int l) {
	int rowStart = l;
	int colStart = l;
	int rowEnd = N - l - 1;
	int colEnd = M - l - 1;

	for (int i = colStart+1; i <= colEnd; ++i) {
		int reverse = colEnd - i;
		tmpBoard[rowStart][i - 1] = board[rowStart][i];
		tmpBoard[rowEnd][i] = board[rowEnd][i-1];
	}
	for (int i = rowStart+1; i <= rowEnd; ++i) {
		int reverse = rowEnd - i;
		tmpBoard[i][colStart] = board[i-1][colStart];
		tmpBoard[i-1][colEnd] = board[i][colEnd];
	}
}

void solution() {
	int numLayers = min(N, M) / 2;
	for (int r = 0; r < R; ++r) {
		for (int l = 0; l < numLayers; ++l) {
			rotate(l);
		}
		memcpy(board, tmpBoard, sizeof(tmpBoard));
	}
	

}

void printData() {
	for (int n = 0; n < N; ++n) {
		for (int m = 0; m < M; ++m) {
			cout << tmpBoard[n][m] << " ";
		}
		cout << endl;
	}
}