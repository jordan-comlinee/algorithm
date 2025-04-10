#if 1
#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
const int ROAD = 0;
const int FIELD = 1;
const int WARRIOR = 1;

int N, M;			// 마을의 크기, 전사의 수
pair<int, int> s;	// 메두사의 집
pair<int, int> e;	// 공원
int m1, m2;
vector<pair<int, int>> petrifiedwarriorsVec;	// 석화된 전사들의 위치
vector<pair<int, int>> activeWarriors;
bool isEscapable = true;
int moveWarriors = 0;				// 총 이동한 횟수
int petrifiedWarriors = 0;			// 석화된 전사들의 수
int attackWarriors = 0;				// 공격한 전사들의 수
int board[MAX][MAX];
int warriorBoard[MAX][MAX];		// 전사들의 위치를 담는 변수, 음수 = 움직일 수 있는 전사, 양수 = 움직일 수 없는 전사
bool medusaView[MAX][MAX] = { false };

// 상 하 좌 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int d2x[4] = { 0, 0, -1, 1 };
int d2y[4] = { -1, 1, 0, 0 };

int px[4] = { 0, 0, 1, -1 };
int py[4] = { 1, -1, 0, 0 };

void inputData();
void printData();
void printBoard(int target[MAX][MAX]);
bool isInRange(int x, int y);
void solution();
pair<int, int> move(int x, int y, int ax[4], int ay[4], int val);
void medusaMove();
void medusaWatch(int dir);
void medusaVision();
void warriorsMove();
void warriorAttack();

int main() {
	inputData();
	solution();
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	cin >> s.first >> s.second >> e.first >> e.second;
	for (int m = 0; m < M; ++m) {
		//cin >> warriors[m].first >> warriors[m].second;
		cin >> m1 >> m2;
		warriorBoard[m1][m2] += WARRIOR;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}
}

void printData() {
	cout << moveWarriors << " " << petrifiedWarriors << " " << attackWarriors << endl;
	moveWarriors = 0;
	petrifiedWarriors = 0;
	attackWarriors = 0;
}

void printBoard(int target[MAX][MAX]) {
	for (int i = 0;i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << target[i][j] << " ";
		}
		cout << endl;
	}
}

bool isInRange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void solution() {
	// 각 턴마다 한 줄에 모든 전사가 이동한 거리의 합, 메두사로 인해 돌이 된 전사의 수, 메두사를 공격한 전사의 수를 공백을 사이에 두고 출력합니다.
	// 단, 메두사가 공원에 도착하면 0을 출력하고 프로그램을 종료합니다.
	while (isEscapable) {
		medusaMove();
		warriorBoard[s.first][s.second] = 0;
		if (s == e) break;
		if (!isEscapable) break;
		medusaVision();
		warriorsMove();
		warriorAttack();
		printData();
	}
	if (!isEscapable) {
		cout << -1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return;
}

// [1] 메두사의 이동
void medusaMove() {
	isEscapable = false;
	int visited[MAX][MAX];
	fill(&visited[0][0], &visited[0][0] + MAX * MAX, -1);
	queue<pair<int, int>> q;
	q.push(e);
	visited[e.first][e.second] = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		if (cur == s) {
			isEscapable = true;
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (isInRange(nx, ny) && board[nx][ny] != FIELD && visited[nx][ny] == -1) {
				visited[nx][ny] = visited[cur.first][cur.second] + 1;
				q.push({ nx, ny });
			}
		}
	}
	int nextVal = INT32_MAX;
	pair<int, int> nextDir;
	for (int i = 0; i < 4; ++i) {
		int nx = s.first + dx[i];
		int ny = s.second + dy[i];
		if (isInRange(nx, ny) && visited[nx][ny] != -1 && nextVal > visited[nx][ny]) {
			nextVal = visited[nx][ny];
			nextDir = { nx, ny };
		}
	}
	s = nextDir;
	return;
}

// [2] 메두사의 시선
// 메두사는 상,하,좌,우 하나의 방향을 선택해 바라봅니다.
// 메두사는 바라보는 방향으로 90도의 시야각을 가지며, 시야각 범위 안에 있는 전사들을 볼 수 있습니다.
void medusaWatch(int dir) {
	int detectedWarriors = 0;
	fill(&medusaView[0][0], &medusaView[0][0] + MAX * MAX, false);
	int visionRange = 1;
	pair<int, int> visionCenter = s;
	vector<pair<int, int>> lefterWarriors;
	vector<pair<int, int>> righterWarriors;
	bool centerBlock = true;
	while (true) {
		// 메두사의 시야 범위를 지정합니다.
		visionCenter.first += dx[dir];
		visionCenter.second += dy[dir];
		if (!isInRange(visionCenter.first, visionCenter.second)) {
			break;
		}
		// 가운데의 시야
		medusaView[visionCenter.first][visionCenter.second] = centerBlock;
		if (warriorBoard[visionCenter.first][visionCenter.second] > 0) {
			centerBlock = false;
		}
		// 왼쪽 범위에 대한 시야
		for (int i = -1; i >= -visionRange; --i) {
			int nx = visionCenter.first + i * px[dir];
			int ny = visionCenter.second + i * py[dir];
			if (isInRange(nx, ny)) {
				medusaView[nx][ny] = true;
			}
			if (warriorBoard[nx][ny] > 0) {
				lefterWarriors.push_back({ nx, ny });
			}
		}
		// 오른쪽 범위에 대한 시야
		for (int i = 1; i <= visionRange; ++i) {
			int nx = visionCenter.first + i * px[dir];
			int ny = visionCenter.second + i * py[dir];
			if (isInRange(nx, ny)) {
				medusaView[nx][ny] = true;
			}
			if (warriorBoard[nx][ny] > 0) {
				righterWarriors.push_back({ nx, ny });
			}
		}
		visionRange++;
	}
	// 전사에 의한 시야 차단 범위를 지정합니다.
	for (auto lw : lefterWarriors) {
		int nx = lw.first + dx[dir];
		int ny = lw.second + dy[dir];
		int cnt = 2;
		while (isInRange(nx, ny)) {
			for (int i = 0; i < cnt; ++i) {
				int sx = nx - px[dir] * i;
				int sy = ny - py[dir] * i;
				if (isInRange(sx, sy)) {
					medusaView[sx][sy] = false;
				}
			}
			nx += dx[dir];
			ny += dy[dir];
			cnt++;
		}
	}
	for (auto rw : righterWarriors) {
		int nx = rw.first + dx[dir];
		int ny = rw.second + dy[dir];
		int cnt = 2;
		while (isInRange(nx, ny)) {
			for (int i = 0; i < cnt; ++i) {
				int sx = nx + px[dir] * i;
				int sy = ny + py[dir] * i;
				if (isInRange(sx, sy)) {
					medusaView[sx][sy] = false;
				}
			}
			nx += dx[dir];
			ny += dy[dir];
			cnt++;
		}
	}
	return;
}

int checkPetrified(bool simulation) {
	int result = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (medusaView[i][j] && warriorBoard[i][j] > 0) {
				// 발견된 전사를 더합니다.
				result += warriorBoard[i][j];
				if (!simulation) {
					petrifiedwarriorsVec.push_back({ i, j });
				}
			}
		}
	}
	return result;
}
// 메두사는 상, 하, 좌, 우 중 가장 전사를 많이 볼 수 있는 방향을 바라봅니다.
// 같은 수의 전사를 볼 수 있는 방향이 여러개라면, 상, 하, 좌, 우의 우선 순위로 방향을 결정합니다.
// 메두사가 바라본 후, 전사들은 돌이 됩니다.
void medusaVision() {
	int maxViewWarrior = 0;
	int maxDir = 0;
	for (int i = 0; i < 4; ++i) {
		medusaWatch(i);
		int curWatch = checkPetrified(true);
		if (maxViewWarrior < curWatch) {
			maxViewWarrior = curWatch;
			maxDir = i;
		}
	}
	(void)medusaWatch(maxDir);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (warriorBoard[i][j] > 0) {
				if (medusaView[i][j]) {
					petrifiedWarriors += warriorBoard[i][j];
				}
				else {
					activeWarriors.push_back({ i, j });
				}
			}
		}
	}
}

// [3] 전사들의 이동
// 돌로 변하지 않은 전사들은 메두사를 향해 최대 두칸까지 도로/비도로를 가리지 않고 이동합니다. 전사들은 이동 중 같은 칸을 공유할 수 있습니다.
// 메두사의 거리를 줄일 수 있는 방향으로 한칸 이동합니다. 이런 방향이 두개 이상일 경우 상하좌우의 우선 순위로 방향을 선택합니다.
// 격자의 바깥으로 나갈 수 없으며, 메두사의 시야에 들어오는 곳으로는 이동할 수 없습니다.

pair<int, int> move(int x, int y, int ax[4], int ay[4], int val) {
	int distance = abs(s.first - x) + abs(s.second - y);
	for (int i = 0; i < 4; ++i) {
		int nx = x + ax[i];
		int ny = y + ay[i];
		if (!isInRange(nx, ny)) continue;
		if (medusaView[nx][ny]) continue;

		int newDistance = abs(s.first - nx) + abs(s.second - ny);
		if (newDistance < distance) {
			warriorBoard[nx][ny] += val;
			moveWarriors += val;
			warriorBoard[x][y] -= val;

			return { nx, ny };
		}
	}
	return { x, y }; // 이동 불가 시 원위치
}

void warriorsMove() {
	vector<pair<pair<int, int>, int>> firstMove;
	vector<pair<pair<int, int>, int>> secondMove;
	for (auto activeWarrior : activeWarriors) {
		firstMove.push_back({activeWarrior, warriorBoard[activeWarrior.first][activeWarrior.second]});
	}
	for (auto activeWarrior : firstMove) {
		pair<int, int> n = move(activeWarrior.first.first, activeWarrior.first.second, dx, dy, activeWarrior.second);
		secondMove.push_back({ n, activeWarrior.second });
	}
	for (auto nextWarrior : secondMove) {
		(void)move(nextWarrior.first.first, nextWarrior.first.second, d2x, d2y, nextWarrior.second);
	}
	activeWarriors.clear();
}

// [4] 전사의 공격
// 메두사와 같은 칸에 도달한 전사는 메두사를 공격하지만, 메두사는 너무 강력해서 이기지 못하고 사라집니다.
void warriorAttack() {
	if (warriorBoard[s.first][s.second] > 0) {
		attackWarriors += warriorBoard[s.first][s.second];
		warriorBoard[s.first][s.second] = 0;
	}
}
#endif
