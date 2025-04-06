#include<bits/stdc++.h>
using namespace std;

const int MAX = 30;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int n;				// �׸��� ũ��
int result;			// ���� ������ ��
int board[MAX][MAX];// �׸�
int tmpBoard[MAX][MAX];
// �׸��� ������ �Է¹޴´�.
void inputData();
bool isInRange(int x, int y);
vector<pair<int, int>> bfs(int x, int y, bool visited[MAX][MAX]);
vector<vector<pair<int, int>>> getGroup();
int getScoreFrom(vector<pair<int, int>> one, vector<pair<int, int>> two);
// �׷� �ֿ� ���� �������� ���Ѵ�.
int getScore();
// ȸ���� �����Ѵ�.
void rotate();
// ��� ���� ����� �ݽð� �������� 90 ȸ���Ѵ�.
void rotateCross();
// �� �� ���簢���� ���� �ð�������� 90 ȸ���Ѵ�.
void rotateSquare(int x, int y);	// ������ �Ǵ� ��ǥ x, y


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
	// �� �׷��� ���Ѵ�.
	groups = getGroup();
	// �� �׷��� ���� �����´�.
	int size = groups.size();
	for (int i = 0; i < size - 1; ++i) {
		for (int j = i+1; j < size; ++j) {
			// �� �׷쿡 ���� ������ ���Ѵ�.
			score += getScoreFrom(groups[i], groups[j]);
		}
	}
	// �´���ִ� ���� ���� ���Ѵ�.
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