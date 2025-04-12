#if 1
#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
const int ROAD = 0;
const int FIELD = 1;
const int WARRIOR = 1;

int N, M;			// ������ ũ��, ������ ��
pair<int, int> s;	// �޵λ��� ��
pair<int, int> e;	// ����
int m1, m2;
vector<pair<int, int>> petrifiedwarriorsVec;	// ��ȭ�� ������� ��ġ
vector<pair<int, int>> activeWarriors;
bool isEscapable = true;
int moveWarriors = 0;				// �� �̵��� Ƚ��
int petrifiedWarriors = 0;			// ��ȭ�� ������� ��
int attackWarriors = 0;				// ������ ������� ��
int board[MAX][MAX];
int warriorBoard[MAX][MAX];		// ������� ��ġ�� ��� ����, ���� = ������ �� �ִ� ����, ��� = ������ �� ���� ����
bool medusaView[MAX][MAX] = { false };

// �� �� �� ��
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
	// �� �ϸ��� �� �ٿ� ��� ���簡 �̵��� �Ÿ��� ��, �޵λ�� ���� ���� �� ������ ��, �޵λ縦 ������ ������ ���� ������ ���̿� �ΰ� ����մϴ�.
	// ��, �޵λ簡 ������ �����ϸ� 0�� ����ϰ� ���α׷��� �����մϴ�.
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

// [1] �޵λ��� �̵�
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

// [2] �޵λ��� �ü�
// �޵λ�� ��,��,��,�� �ϳ��� ������ ������ �ٶ󺾴ϴ�.
// �޵λ�� �ٶ󺸴� �������� 90���� �þ߰��� ������, �þ߰� ���� �ȿ� �ִ� ������� �� �� �ֽ��ϴ�.
void medusaWatch(int dir) {
	int detectedWarriors = 0;
	fill(&medusaView[0][0], &medusaView[0][0] + MAX * MAX, false);
	int visionRange = 1;
	pair<int, int> visionCenter = s;
	vector<pair<int, int>> lefterWarriors;
	vector<pair<int, int>> righterWarriors;
	bool centerBlock = true;
	while (true) {
		// �޵λ��� �þ� ������ �����մϴ�.
		visionCenter.first += dx[dir];
		visionCenter.second += dy[dir];
		if (!isInRange(visionCenter.first, visionCenter.second)) {
			break;
		}
		// ����� �þ�
		medusaView[visionCenter.first][visionCenter.second] = centerBlock;
		if (warriorBoard[visionCenter.first][visionCenter.second] > 0) {
			centerBlock = false;
		}
		// ���� ������ ���� �þ�
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
		// ������ ������ ���� �þ�
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
	// ���翡 ���� �þ� ���� ������ �����մϴ�.
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
				// �߰ߵ� ���縦 ���մϴ�.
				result += warriorBoard[i][j];
				if (!simulation) {
					petrifiedwarriorsVec.push_back({ i, j });
				}
			}
		}
	}
	return result;
}
// �޵λ�� ��, ��, ��, �� �� ���� ���縦 ���� �� �� �ִ� ������ �ٶ󺾴ϴ�.
// ���� ���� ���縦 �� �� �ִ� ������ ���������, ��, ��, ��, ���� �켱 ������ ������ �����մϴ�.
// �޵λ簡 �ٶ� ��, ������� ���� �˴ϴ�.
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

// [3] ������� �̵�
// ���� ������ ���� ������� �޵λ縦 ���� �ִ� ��ĭ���� ����/�񵵷θ� ������ �ʰ� �̵��մϴ�. ������� �̵� �� ���� ĭ�� ������ �� �ֽ��ϴ�.
// �޵λ��� �Ÿ��� ���� �� �ִ� �������� ��ĭ �̵��մϴ�. �̷� ������ �ΰ� �̻��� ��� �����¿��� �켱 ������ ������ �����մϴ�.
// ������ �ٱ����� ���� �� ������, �޵λ��� �þ߿� ������ �����δ� �̵��� �� �����ϴ�.

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
	return { x, y }; // �̵� �Ұ� �� ����ġ
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

// [4] ������ ����
// �޵λ�� ���� ĭ�� ������ ����� �޵λ縦 ����������, �޵λ�� �ʹ� �����ؼ� �̱��� ���ϰ� ������ϴ�.
void warriorAttack() {
	if (warriorBoard[s.first][s.second] > 0) {
		attackWarriors += warriorBoard[s.first][s.second];
		warriorBoard[s.first][s.second] = 0;
	}
}
#endif
