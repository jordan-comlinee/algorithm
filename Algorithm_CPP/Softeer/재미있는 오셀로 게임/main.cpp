#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[9][9] = {0};
const int BLACK = 1;
const int WHITE = -1;
const int dx[4] = { -1, -1, 1, 1 };
const int dy[4] = { -1, 1, -1, 1 };

void printBoard() {
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			string out = "";
			if (board[i][j] == BLACK) {
				out = "B";
			}
			else if (board[i][j] == WHITE) {
				out = "W";
			}
			else{
				out = "O";
			}
			cout << out << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int boardCheck(int color) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] == color){
				cnt++;
			}
		}
	}
	return cnt;
}

void put(int x, int y, int c) {
	if (c == 2){
		board[x][y] = WHITE;
	}
	else{
		board[x][y] = BLACK;
	}
}

void change(int i, int x, int y, int color, bool isVertical) {
	int minPos, maxPos;
	// 가로 부분 오셀로
	if (isVertical){
		minPos = min(i, y);
		maxPos = max(i, y);
		for (int a = minPos+1; a < maxPos; a++){
			if (board[x][a] != 0){
				board[x][a] = color;
			}
		}
	}
	// 세로 부분 오셀로
	else {
		minPos = min(i, x);
		maxPos = max(i, x);
		for (int a = minPos+1; a < maxPos; a++){
			if (board[a][y] != 0) {
				board[a][y] = color;
			}
		}
	}
}

void changeDiagonal(pair<int, int> target, pair<int, int> checkout, int color) {
	int dx = 0, dy = 0;
	if (target.first < checkout.first && target.second < checkout.second) {
		dx = 1; dy = 1;
	}
	else if (target.first < checkout.first && target.second > checkout.second) {
		dx = 1; dy = -1;
	}
	else if (target.first > checkout.first && target.second < checkout.second) {
		dx = -1; dy = 1;
	}
	else if (target.first > checkout.first && target.second > checkout.second) {
		dx = -1; dy = -1;
	}
	int x = target.first + dx;
	int y = target.second + dy;
	while (x != checkout.first && y != checkout.second) {
		if (board[x][y] != 0) {
			board[x][y] = color;
		}
		x += dx;
		y += dy;
	}
}

void osello(int x, int y) {
	for (int i = 1; i <= N; i++){
		if (board[i][y] == board[x][y] && x != i) {
			change(i, x, y, board[x][y], false);
		}
		if (board[x][i] == board[x][y] && y != i) {
			// i~y까지의 구간을 모두 오셀로
			change(i, x, y, board[x][y], true);
		}
	}

	for (int d = 0; d < 4; d++){
		int nx = x + dx[d];
		int ny = y + dy[d];
		while (nx > 0 && nx <= N && ny > 0 && ny <= N) {
			if (board[nx][ny] == board[x][y] && nx != x) {
				changeDiagonal(make_pair(nx, ny), make_pair(x, y), board[x][y]);
			}
			nx += dx[d];
			ny += dy[d];
		}
	}

}

void init() {
	memset(board, 0, sizeof(board));
	board[N / 2][N / 2] = WHITE;
	board[N / 2 + 1][N / 2 + 1] = WHITE;
	board[N / 2][N / 2 + 1] = BLACK;
	board[N / 2 + 1][N / 2] = BLACK;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t < T+1; t++) {
		int black, white;
		cin >> N >> M;
		init();
		for (int m = 0; m < M; m++) {
			int x, y, c;
			cin >> x >> y >> c;
			put(x, y, c);
			osello(x, y);
		}
		black = boardCheck(BLACK);
		white = boardCheck(WHITE);
		cout << "#" << t << " " << black << " " << white << endl;
	}
}