#if 1
#include <bits/stdc++.h>
using namespace std;

const int MAX = 21;
int n, m, K, c; // 격자의 크기, 박멸 진행 기간, 확산 범위, 제초제 잔여 수
int board[MAX][MAX];	// 나무 지도
int killBoard[MAX][MAX];// 제초제가 있는 위치
int result;		// 박멸한 나무의 그루 수
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int cx[2] = { 1, -1 };
int cy[2] = { 1, -1 };
typedef struct _tree {
	int val;
	int first;
	int second;
}Tree;

bool isInRange(int x, int y);
void inputData();
void printData();
void growReproduce();
int getAvailableKill(int x, int y);
void kill();

int main() {
	inputData();
	for (int i = 0; i < m; ++i) {
		growReproduce();
		kill();
	}
	cout << result << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> K >> c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}
}

bool isInRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n && board[x][y] != -1);
}

void printData() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
// 인접한 네개의 칸의 수 만큼 나무가 성장한다. 성장은 모든 나무에게 동시에 일어난다.
// 기존에 있었던 나무들은 인접한 4개의 칸 중 벽, 다른 나무, 제초제 모두 없는 칸에 번식한다.
// 각 칸의 나무 그루 수에서 총 번식이 가능한 칸의 개수만큼 나누어진 그루 수만큼 번식이 된다.
// 번식의 과정은 모든 나무에서 동시에 일어난다.
void growReproduce() {
	queue<Tree> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// 칸에 나무가 있는지 확인한다.
			if (board[i][j] > 0) {
				int growth = 0, noneBlock = 0;
				vector<pair<int, int>> none;
				// 네개 칸에 나무가 있는 지 확인한다.
				for (int k = 0; k < 4; ++k) {
					if (isInRange(i + dx[k], j + dy[k])) {
						if (board[i + dx[k]][j + dy[k]] > 0) growth++;
						else if (board[i + dx[k]][j + dy[k]] == 0 && killBoard[i+dx[k]][j+dy[k]] == 0) {
							noneBlock++;
							none.push_back({ i + dx[k], j + dy[k] });
						}
					}
				}
				board[i][j] += growth;
				// 각 칸의 나무 그루 수에서 총 번식이 가능한 칸의 개수만큼 나누어진 그루 수만큼 번식이 된다.
				if (noneBlock > 0) {
					int reproduceVal = board[i][j] / noneBlock;
					// 번식이 되는 부분은 큐에 저장한다.
					for (auto n : none) {
						q.push({ reproduceVal, n.first, n.second });
					}
				}

			}
		}
	}
	// 한꺼번에 번식을 진행한다.
	while (!q.empty()) {
		Tree newTree = q.front();
		q.pop();
		if (killBoard[newTree.first][newTree.second] == 0) {
			board[newTree.first][newTree.second] += newTree.val;
		}
	}
}

int getAvailableKill(int x, int y) {
	int killedTree = board[x][y];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			int k = 1;
			for (int k = 1; k <= K; ++k) {
				int nx = x + cx[i] * k;
				int ny = y + cy[j] * k;

				if (!isInRange(nx, ny)) break;
				if (board[nx][ny] == -1) break;
				killedTree += board[nx][ny];
				if (board[nx][ny] == 0) break;
			}
		}
	}
	return killedTree;
}

// 각 칸 중, 제초제를 뿌렸을 때 나무가 가장 많이 작멸되는 칸에 제초제를 뿌린다.
// 나무가 없는 칸에 제초제를 뿌리면 박멸되는 나무가 전혀 없는 상태로 끝난다.
// 제초제가 뿌려진 칸에는 c년 만큼 제초제가 남아있다.
// 제초제가 뿌려져 있는 곳에 다시 뿌리면, c년 동안 제초제가 남는다.
void kill() {
	// 제초제를 뿌릴 위치를 선정한다.
	Tree killSpot = { 0, 0, 0 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// 제초제가 제거된다.
			killBoard[i][j] = killBoard[i][j] > 0 ? killBoard[i][j] - 1 : 0;
			int availableKill = 0;
			if (board[i][j] > 0) {
				availableKill = getAvailableKill(i, j);
				if (killSpot.val < availableKill) {
					killSpot.val = availableKill;
					killSpot.first = i; killSpot.second = j;
				}
			}
		}
	}
	// 제초제를 뿌린 후, X자로 c 만큼의 제초제가 남는다.
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			int k = 1;
			for (int k = 1; k <= K; ++k) {
				int nx = killSpot.first + cx[i] * k;
				int ny = killSpot.second + cy[j] * k;

				if (!isInRange(nx, ny)) break;
				if (board[nx][ny] == -1) break;
				killBoard[nx][ny] = c;
				if (board[nx][ny] == 0) break;
				board[nx][ny] = 0;
				
			}
		}
	}
	board[killSpot.first][killSpot.second] = 0;
	killBoard[killSpot.first][killSpot.second] = c;
	result += killSpot.val;
}

#endif