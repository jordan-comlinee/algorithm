// �� ����� ��ġ�� �� �� index�� ���Ѵ�.
// ��� ���� ���� ��ǥ �� �Ÿ��� ���Ѵ�.
// board[x][y] != 0 �� ���, ���̶�� ���̹Ƿ� �� �Ÿ��� ���Ͽ� �ּڰ��� ���Ѵ�.
// �� ��, 0�� ���� �� ������, 0 �� ���� �����Ѵ�.


#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = { 0, 0, -1, 1 };
const int MAX = 101;
int minBridge = INT32_MAX;
int N, islandIdx = 0;
int board[MAX][MAX];
bool visited[MAX][MAX];

void inputData();
void getIslandNum();
bool inRange(int x, int y);
void bfs(int x, int y, int idx);
void printBoard();
void solution();
void getMinimumDistance();

int main() {
	inputData();
	solution();
	cout << minBridge << endl;
	return 0;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}
	return;
}

bool inRange(int x, int y) {
	return (0 <= x && x < N && 0 <= y && y < N);
}

void bfs(int x, int y, int islandIdx) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	board[x][y] = islandIdx;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (inRange(nx, ny) && !visited[nx][ny] && board[nx][ny] == 1) {
				visited[nx][ny] = true;
				board[nx][ny] = islandIdx;
				q.push({ nx, ny });
			}
		}
	}
}

void printBoard() {
	for (int i = 0; i < N; ++i)	{
		for (int j = 0; j < N; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

//�� ����� ��ġ�� �� �� index�� ���Ѵ�.
void getIslandNum() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j] && board[i][j] == 1) {
				islandIdx++;
				bfs(i, j, islandIdx);
			}
		}
	}
}
void getMinimumDistance() {
	for (int i = 1; i <= islandIdx; ++i) {
		memset(visited, false, sizeof(visited));
		queue<pair<pair<int, int>, int>> q;

		// ���� ���� ��� ��ǥ���� BFS ����
		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < N; ++y) {
				if (board[x][y] == i) {
					q.push({ {x, y}, 0 });
					visited[x][y] = true;
				}
			}
		}

		while (!q.empty()) {
			pair<pair<int, int>, int> cur = q.front();
			q.pop();
			int x = cur.first.first;
			int y = cur.first.second;
			int dist = cur.second;

			for (int d = 0; d < 4; ++d) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (!inRange(nx, ny) || visited[nx][ny]) continue;

				// �ٸ� ���� ���� ���
				if (board[nx][ny] != 0 && board[nx][ny] != i) {
					minBridge = min(minBridge, dist);
					continue;
				}

				if (dist < minBridge && board[nx][ny] == 0) {
					visited[nx][ny] = true;
					q.push({ {nx, ny}, dist + 1 });
				}
			}
		}
	}
}


void solution() {
	getIslandNum();
	//cout << islandIdx << " =====================" << endl;
	//printBoard();
	getMinimumDistance();
	return;
}