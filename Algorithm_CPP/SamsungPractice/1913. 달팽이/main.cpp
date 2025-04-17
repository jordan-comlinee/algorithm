#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1001;
int N, T;
pair<int, int> pos;
int board[MAX][MAX];

bool isInRange(int x, int y);
void makeSnail();
void printData();


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> T;
	makeSnail();
	printData();
	cout << pos.first << " " << pos.second << endl;
}

bool isInRange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}


void makeSnail() {
	fill(&board[0][0], &board[0][0] + MAX * MAX, 0);
	int a = pow(N, 2);
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	pair<int, int> startPoint = { 0, 0 };
	int dir = 0;
	int x = 0, y = 0;
	while (a > 0) {
		if (a == T) {
			pos = { x + 1, y + 1 };
		}
		board[x][y] = a--;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (!isInRange(nx, ny) || board[nx][ny] != 0) {
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		x = nx;
		y = ny;
	}
}
void printData() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}