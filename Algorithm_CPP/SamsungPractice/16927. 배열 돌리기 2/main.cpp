#include <bits/stdc++.h>
using namespace std;

const int MAX = 300;
int N, M, R;
int board[MAX][MAX];
int tmpBoard[MAX][MAX];

void inputData();
void rotate(int l, int n);
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

void rotate(int l, int n) {
	int rowStart = l;
	int colStart = l;
	int rowEnd = N - l - 1;
	int colEnd = M - l - 1;

	vector<int> tmp;

	// 1. 반시계 방향으로 레이어 저장
	for (int i = colStart; i <= colEnd; ++i) tmp.push_back(board[rowStart][i]);
	for (int i = rowStart + 1; i <= rowEnd; ++i) tmp.push_back(board[i][colEnd]);
	for (int i = colEnd - 1; i >= colStart; --i) tmp.push_back(board[rowEnd][i]);
	for (int i = rowEnd - 1; i > rowStart; --i) tmp.push_back(board[i][colStart]);

	// 2. 회전
	int len = tmp.size();
	rotate(tmp.begin(), tmp.begin() + n, tmp.end());

	// 3. 회전된 값 다시 넣기
	int idx = 0;
	for (int i = colStart; i <= colEnd; ++i) tmpBoard[rowStart][i] = tmp[idx++];
	for (int i = rowStart + 1; i <= rowEnd; ++i) tmpBoard[i][colEnd] = tmp[idx++];
	for (int i = colEnd - 1; i >= colStart; --i) tmpBoard[rowEnd][i] = tmp[idx++];
	for (int i = rowEnd - 1; i > rowStart; --i) tmpBoard[i][colStart] = tmp[idx++];

	
}

void solution() {
	int numLayers = min(N, M) / 2;
	for (int l = 0; l < numLayers; ++l) {
		int height = N - 2 * l;
		int width = M - 2 * l;
		int rotateNum = 2 * (height + width) - 4;
		rotate(l, R % rotateNum);
	}
	memcpy(board, tmpBoard, sizeof(tmpBoard));

}

void printData() {
	for (int n = 0; n < N; ++n) {
		for (int m = 0; m < M; ++m) {
			cout << tmpBoard[n][m] << " ";
		}
		cout << endl;
	}
}