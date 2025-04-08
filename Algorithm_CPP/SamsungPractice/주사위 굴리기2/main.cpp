#include <bits/stdc++.h>
using namespace std;

const int MAX = 21;

int N, M, K;	// 세로, 가로, 이동 횟수
int maps[MAX][MAX];
int scoreMap[MAX][MAX] = { 0 };
int result = 0;
pair<int, int> currentDice = { 0, 0 };
int dir = 0;
int dice[6] = {1, 6, 4, 3, 5, 2};
int currentTop = 1;
int diceUnderVal[7] = { 0, 6, 5, 4, 3, 2, 1 };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void inputData();
void solution();
bool isInRange(int x, int y);
int getScore(int x, int y);
int rollDice();
void updateDice();
void getScoreMap();

int main() {
	inputData();
	solution();
	cout << result << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> maps[i][j];
		}
	}
}

bool isInRange(int x, int y) {
	return (0 <= x && x < N && 0 <= y && y < M);
}

int getScore(int x, int y) {
	int sumScore = maps[x][y];
	bool visited[MAX][MAX] = { false };
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({x, y});
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (isInRange(nx, ny) && !visited[nx][ny] && maps[nx][ny] == maps[x][y]) {
				visited[nx][ny] = true;
				sumScore += maps[x][y];
				q.push({ nx, ny });
			}
		}
	}
	return sumScore;
}

void getScoreMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scoreMap[i][j] = getScore(i, j);
		}
	}
}

void updateDice() {
	int up, down, left, right, front, back;
	up = dice[0];
	down = dice[1];
	left = dice[2];
	right = dice[3];
	front = dice[4];
	back = dice[5];
	switch (dir)
	{
	case 0 : 
		dice[0] = left;
		dice[1] = right;
		dice[2] = down;
		dice[3] = up;
		break;
	case 1 :
		dice[0] = back;
		dice[1] = front;
		dice[4] = up;
		dice[5] = down;
		break;
	case 2 :
		dice[0] = right;
		dice[1] = left;
		dice[2] = up;
		dice[3] = down;
		break;
	case 3 :
		dice[0] = front;
		dice[1] = back;
		dice[4] = down;
		dice[5] = up;
		break;
	default :
		break;
	}
}

int rollDice() {
	int A = 0, B = 0;
	int score = 0;
	int nx = currentDice.first + dx[dir];
	int ny = currentDice.second + dy[dir];

	if (!isInRange(nx, ny)) {
		dir = (dir + 2) % 4;
		nx = currentDice.first + dx[dir];
		ny = currentDice.second + dy[dir];
	}
	currentDice = { nx, ny };
	updateDice();
	currentTop = dice[0];
	B = maps[nx][ny];
	A = diceUnderVal[currentTop];
	score = scoreMap[nx][ny];
	if (A > B) {
		dir = (dir + 1) % 4;
	}
	else if (A < B) {
		dir = (dir + 3) % 4;
	}
	return score;
}

void solution() {
	getScoreMap();
	for (int k = 0; k < K; ++k) {
		result += rollDice();
	}
	return;
}