#include <bits/stdc++.h>
using namespace std;

int N;
int board[65][65] = {0};

void printBoard() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool isInRightPlace(int i, int j) {
	return ( board[i][j] == ((i - 1) * N + j));
}

bool isAllInRightPlace() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!isInRightPlace(i, j)) {
				return false;
			}
		}
	}
	return true;
}

void transpose(int x) {
	for (int i = 1; i < x; i++){
		for (int j = i+1; j <= x; j++){
			int tmp = board[i][j];
			board[i][j] = board[j][i];
			board[j][i] = tmp;
		}
	}
}

int countTranspose() {
	int cnt = 0;
	while (!isAllInRightPlace()){
		for (int i = N; i > 0; i--) {
			if (!isInRightPlace(1, i)) {
				transpose(i);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		int result = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> board[i][j];
			}
		}
		if (!isAllInRightPlace()){
			result = countTranspose();
		}
		cout << result << endl;
		memset(board, 0, sizeof(board));
	}
}