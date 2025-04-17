# if 1
#include <iostream>
#include <vector>
#include <cMath>
#include <queue>
#include <map>
using namespace std;

const int MAX = 100;
int N;
int board[MAX][MAX];
int tmpBoard[MAX][MAX];

void inputData();
void rotateClock();
void rotateReverse();
void printData();
void makeSnail();


int main() {
	inputData();
	//rotateClock();
	//printData();
	//cout << "=================" << endl;
	//rotateReverse();
	//printData();
	makeSnail();
	cout << "=================" << endl;
	printData();

}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < N; ++j) {
	//		cin >> board[i][j];
	//	}
	//}
}

void rotateClock() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			tmpBoard[j][N-1-i] = board[i][j];
		}
	}
}

void rotateReverse() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			tmpBoard[N-1-j][i] = board[i][j];
		}
	}
}

void printData() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << tmpBoard[i][j] << " ";
		}
		cout << endl;
	}
}

bool isInRange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void makeSnail() {
	fill(&tmpBoard[0][0], &tmpBoard[0][0] + MAX*MAX, 0);
	int a = pow(N, 2);
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	pair<int, int> startPoint = { 0, 0 };
	int dir = 0;
	int x = 0, y = 0;
	while (a > 0) {
		tmpBoard[x][y] = a--;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (!isInRange(nx, ny) || tmpBoard[nx][ny] != 0) {
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		x = nx;
		y = ny;
	}
}


#endif

#if 0
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
			pos = { x+1, y+1 };
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
#endif

#if 0

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

const int MAX = 30;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

int n;
int board[MAX][MAX];
int tmpBoard[MAX][MAX];
int result;

void inputData();
void rotate();
vector<pair<int, int>> bfs(int x, int y, bool visited[MAX][MAX]);
vector<vector<pair<int, int>>> getGroup();
void rotateCross();
void rotateSquare(int x, int y);
bool isInRange(int x, int y);
int getScoreFrom(vector<pair<int, int>>one, vector<pair<int, int>> two);
int getScore();

int main() {
	inputData();
	for (int i = 0; i < 4; ++i) {
		result += getScore();
		rotate();
	}
	cout << result << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}
}

bool isInRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

vector<pair<int, int>> bfs(int x, int y, bool visited[MAX][MAX]) {
	vector<pair<int, int>> group;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		group.push_back(cur);
		for (int i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (isInRange(nx, ny) && !visited[nx][ny] && board[nx][ny] == board[x][y]) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
	return group;
}

vector<vector<pair<int, int>>> getGroup() {
	vector<vector<pair<int, int>>> groups;
	bool visited[MAX][MAX];
	fill(&visited[0][0], &visited[0][0] + MAX * MAX, false);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visited[i][j]) {
				vector<pair<int, int>> group = bfs(i, j, visited);
				groups.push_back(group);
			}
		}
	}
	return groups;
}

int getScoreFrom(vector<pair<int, int>>one, vector<pair<int, int>> two) {
	int attached = 0;
	int oneVal = board[one[0].first][one[0].second];
	int twoVal = board[two[0].first][two[0].second];
	set<pair<int, int>> twoSet(two.begin(), two.end());
	for (auto o : one) {
		for (int dir = 0; dir < 4; ++dir) {
			int nx = o.first + dx[dir];
			int ny = o.second + dy[dir];
			if (isInRange(nx, ny) && twoSet.count({ nx, ny })) {
				attached++;
			}
		}
	}
	return (one.size() + two.size()) * oneVal * twoVal * attached;
}

int getScore() {
	int score = 0;
	vector<vector<pair<int, int>>> groups;
	groups = getGroup();
	int size = groups.size();
	for (int i = 0; i < size - 1; ++i) {
		for (int j = i+1; j < size; ++j) {
			score += getScoreFrom(groups[i], groups[j]);
		}
	}
	return score;
}

void rotateCross() {
	int mid = n / 2;
	for (int i = 0; i < n; ++i) {
		tmpBoard[mid][i] = board[i][mid];
	}
	for (int i = 0; i < n; ++i) {
		tmpBoard[n - i - 1][mid] = board[mid][i];
	}
}

void rotateSquare(int x, int y) {
	int len = n / 2;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			tmpBoard[x + j][y + len - 1 - i] = board[x + i][y + j];
		}
	}
}

void rotate() {
	rotateCross();
	rotateSquare(0, 0);
	rotateSquare(n/2+1, 0);
	rotateSquare(0, n/2+1);
	rotateSquare(n/2+1, n/2+1);
	memcpy(board, tmpBoard, sizeof(board));
}


#endif