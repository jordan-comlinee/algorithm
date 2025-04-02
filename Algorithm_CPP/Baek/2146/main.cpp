// 각 대륙의 위치와 섬 별 index를 구한다.
// 대륙 별로 지도 좌표 별 거리를 구한다.
// board[x][y] != 0 인 경우, 섬이라는 뜻이므로 각 거리를 비교하여 최솟값을 구한다.
// 이 때, 0은 나올 수 없으니, 0 인 경우는 제외한다.


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

//각 대륙의 위치와 섬 별 index를 구한다.
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

		// 현재 섬의 모든 좌표에서 BFS 시작
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

				// 다른 섬을 만난 경우
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