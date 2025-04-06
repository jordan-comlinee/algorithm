#include<bits/stdc++.h>
using namespace std;

const int MAX = 30;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int n;				// 그림의 크기
int result;			// 예술 점수의 합
int board[MAX][MAX];// 그림
int tmpBoard[MAX][MAX];
// 그림의 정보를 입력받는다.
void inputData();
bool isInRange(int x, int y);
vector<pair<int, int>> bfs(int x, int y, bool visited[MAX][MAX]);
vector<vector<pair<int, int>>> getGroup();
int getScoreFrom(vector<pair<int, int>> one, vector<pair<int, int>> two);
// 그룹 쌍에 대한 예술성을 구한다.
int getScore();
// 회전을 수행한다.
void rotate();
// 가운데 십자 모양은 반시계 방향으로 90 회전한다.
void rotateCross();
// 그 외 정사각형에 대해 시계방향으로 90 회전한다.
void rotateSquare(int x, int y);	// 기준이 되는 좌표 x, y


int main() {
	inputData();
	//result += getScore();
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
	bool visited[MAX][MAX] = { false };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visited[i][j]) {
				vector<pair<int, int>>group = bfs(i, j, visited);
				groups.push_back(group);
			}
		}
	}
	return groups;
}

int getScoreFrom(vector<pair<int, int>> one, vector<pair<int, int>> two) {
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
	// 각 그룹을 구한다.
	groups = getGroup();
	// 각 그룹의 쌍을 가져온다.
	int size = groups.size();
	for (int i = 0; i < size - 1; ++i) {
		for (int j = i+1; j < size; ++j) {
			// 각 그룹에 대한 정보를 구한다.
			score += getScoreFrom(groups[i], groups[j]);
		}
	}
	// 맞닿아있는 변의 수를 구한다.
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
	rotateSquare(n / 2 + 1, 0);
	rotateSquare(0, n / 2 + 1);
	rotateSquare(n / 2 + 1, n / 2 + 1);
	for(int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			board[i][j] = tmpBoard[i][j];
		}
	}

}