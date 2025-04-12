# if 01
#include <bits/stdc++.h>
using namespace std;

struct Square {
	int x;
	int y;
	int val;
	Square(int x, int y, int val) : x(x), y(y), val(val) {};
};

const int MAX = 11;
const int EXIT = INT32_MIN;
// �̷��� ũ��, ������ ��, ���� �ð�
int N, M, K, x, y;
// �̵� �Ÿ� ��
int pMove = 0;
int board[MAX][MAX];
vector<pair<int, int>> participants;
pair<int, int> exitPoint;
// ��, ��, ��, ���� ����
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void inputData();
bool isInRange(int x, int y);
int getDistance(int x, int y);
void participantsMove();
Square getSmallest();
void rotateSquare(Square s);
void updateInfo();
void printInfo();
void solution();


int main() {
	inputData();
	solution();
	printInfo();
	cout << pMove << endl;
	cout << exitPoint.first << " " << exitPoint.second << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < M; ++i) {
		cin >> x >> y;
		participants.push_back({ x, y });
		--board[x][y];
	}
	cin >> exitPoint.first >> exitPoint.second;
	board[exitPoint.first][exitPoint.second] = EXIT;
}

bool isInRange(int x, int y) {
	return 1 <= x && x <= N && 1 <= y && y <= N;
}

int getDistance(int x, int y) {
	return (abs(exitPoint.first - x) + abs(exitPoint.second - y));
}

// 1�ʸ��� �����ڴ� ��ĭ�� �����Դϴ�.
void participantsMove() {
	for (auto& participant : participants) {
		int distance = getDistance(participant.first, participant.second);
		for (int i = 0; i < 4; ++i) {
			int nx = participant.first + dx[i];
			int ny = participant.second + dy[i];
			if (isInRange(nx, ny) && board[nx][ny] <= 0) {
				if (getDistance(nx, ny) == 0) {
					pMove -= board[participant.first][participant.second];
					board[participant.first][participant.second] = 0;
					participant.first = nx;
					participant.second = ny;
					break;
				}
				else if (getDistance(nx, ny) < distance) {
					board[nx][ny] += board[participant.first][participant.second];
					pMove -= board[participant.first][participant.second];
					board[participant.first][participant.second] = 0;
					participant.first = nx;
					participant.second = ny;
					break;
				}
			}
		}
	}
}

// �����ڰ� �̵��� ��������, �����ڿ� �̷� ���簢���� ���� ���� ���� ���մϴ�.
Square getSmallest() {
	for (int sz = 2; sz <= N; sz++) {
		for (int x1 = 1; x1 <= N - sz + 1; x1++) {
			for (int y1 = 1; y1 <= N - sz + 1; y1++) {
				int x2 = x1 + sz - 1;
				int y2 = y1 + sz - 1;

				// �ⱸ�� ���ԵǾ� ���� ������ ��ŵ
				if (!(x1 <= exitPoint.first && exitPoint.first <= x2 &&
					y1 <= exitPoint.second && exitPoint.second <= y2)) {
					continue;
				}

				// �� �� �̻��� �����ڰ� ���ԵǾ� �ִ��� Ȯ��
				bool isTravelerIn = false;
				for (int l = 0; l < participants.size(); l++) {
					int tx = participants[l].first;
					int ty = participants[l].second;

					// �ⱸ�� �ִ� �����ڴ� ����
					if (tx == exitPoint.first && ty == exitPoint.second) continue;

					if (x1 <= tx && tx <= x2 && y1 <= ty && ty <= y2) {
						isTravelerIn = true;
						break;
					}
				}

				if (isTravelerIn) {
					return Square(x1, y1, sz - 1);  // sz-1�� ���簢���� �� �� �Ÿ�
				}
			}
		}
	}

	// �� ã�� ��� - �������� �ʴ� �� ����
	return Square(-1, -1, -1);
}


// �̷ΰ� ȸ���մϴ�.
void rotateSquare(Square s) {
	int len = s.val + 1;
	int tmpBoard[MAX][MAX];
	//int len = s.val / 2;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			tmpBoard[s.x + j][s.y + len-1-i] = board[s.x + i][s.y + j] > 0 ? board[s.x+i][s.y+j]-1 : board[s.x+i][s.y+j];
			
		}
	}
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			board[s.x + i][s.y + j] = tmpBoard[s.x + i][s.y + j];
		}
	}
}

// �������� ��ġ�� �ⱸ�� ��ġ�� ������Ʈ�մϴ�.
void updateInfo() {
	participants.clear();
	for(int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (board[i][j] == EXIT) {
				exitPoint = {i, j};
			}
			else if (board[i][j] < 0) {
				participants.push_back({ i, j });
			}
		}
	}
}

void printInfo() {
	cout << "=================" << endl;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (board[i][j] == EXIT) {
				cout << "X ";
			}
			else {
				cout << board[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << "Exit point is at " << exitPoint.first << " " << exitPoint.second << endl;
	cout << "=================" << endl;
}

void solution() {
	for (int i = 0;i < K; ++i) {
		// 1�ʸ��� �����ڴ� ��ĭ�� �����Դϴ�.
		participantsMove();
		updateInfo();
		//printInfo();
		if (participants.size() == 0) break;
		// �����ڰ� �̵��� ��������, �����ڿ� �̷� ���簢���� ���� ���� ���� ���մϴ�.
		Square s = getSmallest();
		// �̷ΰ� ȸ���մϴ�.
		rotateSquare(s);
		// �������� ��ġ�� �ⱸ�� ��ġ�� ��� �ٲ�����Ƿ�, �� ������ ������Ʈ�մϴ�.
		updateInfo();
		// ��� �����ڰ� Ż�⿡ �����ϸ�, ������ �����ϴ�.
		if (participants.size() == 0) {
			break;
		}
	}
}
#endif

#if 0
#include <iostream>

using namespace std;

#define MAX_N 10

int n, m, k;

// ��� ������ ���¸� ������ݴϴ�.
int board[MAX_N + 1][MAX_N + 1];

// ȸ���� ������ ���ϰ� �ϱ� ���� 2���� �迭�� �ϳ� �� �������ݴϴ�.
int next_board[MAX_N + 1][MAX_N + 1];

// �������� ��ġ ������ ������ݴϴ�.
pair<int, int> traveler[MAX_N + 1];

// �ⱸ�� ��ġ ������ ������ݴϴ�.
pair<int, int> exits;

// ����(��� �����ڵ��� �̵� �Ÿ� ��)�� ������ݴϴ�.
int ans;

// ȸ���ؾ� �ϴ� �ּ� ���簢���� ã�� ������ݴϴ�.
int sx, sy, square_size;

// ��� �����ڸ� �̵���ŵ�ϴ�.
void MoveAllTraveler() {
	// m���� ��� �����ڵ鿡 ���� �̵��� �����մϴ�.
	for (int i = 1; i <= m; i++) {
		// �̹� �ⱸ�� �ִ� ��� ��ŵ�մϴ�.
		if (traveler[i].first == exits.first && traveler[i].second == exits.second)
			continue;

		// ���� �ٸ� ��� ���� �̵����Ѻ��ϴ�.
		if (traveler[i].first != exits.first) {
			int nx = traveler[i].first;
			int ny = traveler[i].second;

			if (exits.first > nx) nx++;
			else nx--;

			// ���� ���ٸ� ���� �̵���ų �� �ֽ��ϴ�.
			// �� ��� ���� �̵���Ű�� �ٷ� ���� �����ڷ� �Ѿ�ϴ�.
			if (!board[nx][ny]) {
				traveler[i].first = nx;
				traveler[i].second = ny;
				ans++;
				continue;
			}
		}

		// ���� �ٸ� ��� ���� �̵����Ѻ��ϴ�.
		if (traveler[i].second != exits.second) {
			int nx = traveler[i].first;
			int ny = traveler[i].second;

			if (exits.second > ny) ny++;
			else ny--;

			// ���� ���ٸ� ���� �̵���ų �� �ֽ��ϴ�.
			// �� ��� ���� �̵���ŵ�ϴ�.
			if (!board[nx][ny]) {
				traveler[i].first = nx;
				traveler[i].second = ny;
				ans++;
				continue;
			}
		}
	}
}

// �� �� �̻��� �����ڿ� �ⱸ�� ������ ���� ���� ���簢���� ã���ϴ�.
void FindMinimumSquare() {
	// ���� ���� ���簢������ ��� ���簢���� �����ϴ�.
	for (int sz = 2; sz <= n; sz++) {
		// ���� �»�� r ��ǥ�� ���� �ͺ��� �ϳ��� �����ϴ�.
		for (int x1 = 1; x1 <= n - sz + 1; x1++) {
			// ���� �»�� c ��ǥ�� ���� �ͺ��� �ϳ��� �����ϴ�.
			for (int y1 = 1; y1 <= n - sz + 1; y1++) {
				int x2 = x1 + sz - 1;
				int y2 = y1 + sz - 1;

				// ���� �ⱸ�� �ش� ���簢�� �ȿ� ���ٸ� ��ŵ�մϴ�.
				if (!(x1 <= exits.first && exits.first <= x2 && y1 <= exits.second && exits.second <= y2)) {
					continue;
				}

				// �� �� �̻��� �����ڰ� �ش� ���簢�� �ȿ� �ִ��� �Ǵ��մϴ�.
				bool is_traveler_in = false;
				for (int l = 1; l <= m; l++) {
					if (x1 <= traveler[l].first && traveler[l].first <= x2 && y1 <= traveler[l].second && traveler[l].second <= y2) {
						// �ⱸ�� �ִ� �����ڴ� �����մϴ�.
						if (!(traveler[l].first == exits.first && traveler[l].second == exits.second)) {
							is_traveler_in = true;
						}
					}
				}

				// ���� �� �� �̻��� �����ڰ� �ش� ���簢�� �ȿ� �ִٸ�
				// sx, sy, sqaure_size ������ �����ϰ� �����մϴ�.
				if (is_traveler_in) {
					sx = x1;
					sy = y1;
					square_size = sz;

					return;
				}
			}
		}
	}
}

// ���簢�� ������ ���� ȸ����ŵ�ϴ�.
void RotateSquare() {
	// �켱 ���簢�� �ȿ� �ִ� ������ 1 ���ҽ�ŵ�ϴ�.
	for (int x = sx; x < sx + square_size; x++)
		for (int y = sy; y < sy + square_size; y++) {
			if (board[x][y]) board[x][y]--;
		}

	// ���簢���� �ð�������� 90' ȸ���մϴ�.
	for (int x = sx; x < sx + square_size; x++)
		for (int y = sy; y < sy + square_size; y++) {
			// Step 1. (sx, sy)�� (0, 0)���� �Ű��ִ� ��ȯ�� �����մϴ�. 
			int ox = x - sx, oy = y - sy;
			// Step 2. ��ȯ�� ���¿����� ȸ�� ������ ��ǥ�� (x, y) -> (y, square_n - x - 1)�� �˴ϴ�.
			int rx = oy, ry = square_size - ox - 1;
			// Step 3. �ٽ� (sx, sy)�� �����ݴϴ�.
			next_board[rx + sx][ry + sy] = board[x][y];
		}

	// next_board ���� ���� board�� �Ű��ݴϴ�.
	for (int x = sx; x < sx + square_size; x++)
		for (int y = sy; y < sy + square_size; y++) {
			board[x][y] = next_board[x][y];
		}
}

// ��� �����ڵ� �� �ⱸ�� ȸ����ŵ�ϴ�.
void RotateTravelerAndExit() {
	// m���� �����ڵ��� ��� Ȯ���մϴ�.
	for (int i = 1; i <= m; i++) {
		int x = traveler[i].first;
		int y = traveler[i].second;
		// �ش� �����ڰ� ���簢�� �ȿ� ���ԵǾ� ���� ������ ȸ����ŵ�ϴ�.
		if (sx <= x && x < sx + square_size && sy <= y && y < sy + square_size) {
			// Step 1. (sx, sy)�� (0, 0)���� �Ű��ִ� ��ȯ�� �����մϴ�. 
			int ox = x - sx, oy = y - sy;
			// Step 2. ��ȯ�� ���¿����� ȸ�� ������ ��ǥ�� (x, y) -> (y, square_n - x - 1)�� �˴ϴ�.
			int rx = oy, ry = square_size - ox - 1;
			// Step 3. �ٽ� (sx, sy)�� �����ݴϴ�.
			traveler[i] = make_pair(rx + sx, ry + sy);
		}
	}

	// �ⱸ���� ȸ���� �����մϴ�.
	int x = exits.first;
	int y = exits.second;
	if (sx <= x && x < sx + square_size && sy <= y && y < sy + square_size) {
		// Step 1. (sx, sy)�� (0, 0)���� �Ű��ִ� ��ȯ�� �����մϴ�. 
		int ox = x - sx, oy = y - sy;
		// Step 2. ��ȯ�� ���¿����� ȸ�� ������ ��ǥ�� (x, y) -> (y, square_n - x - 1)�� �˴ϴ�.
		int rx = oy, ry = square_size - ox - 1;
		// Step 3. �ٽ� (sx, sy)�� �����ݴϴ�.
		exits = make_pair(rx + sx, ry + sy);
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];

	for (int i = 1; i <= m; i++) {
		cin >> traveler[i].first;
		cin >> traveler[i].second;
	}

	cin >> exits.first;
	cin >> exits.second;

	while (k--) {
		// ��� �����ڸ� �̵���ŵ�ϴ�.
		MoveAllTraveler();

		// ��� ����� �ⱸ�� Ż���ߴ��� �Ǵ��մϴ�.
		bool is_all_escaped = true;
		for (int i = 1; i <= m; i++) {
			if (!(traveler[i].first == exits.first && traveler[i].second == exits.second)) {
				is_all_escaped = false;
			}
		}

		// ���� ��� ����� �ⱸ�� Ż�������� �ٷ� �����մϴ�.
		if (is_all_escaped) break;

		// �� �� �̻��� �����ڿ� �ⱸ�� ������ ���� ���� ���簢���� ã���ϴ�.
		FindMinimumSquare();

		// ���簢�� ������ ���� ȸ����ŵ�ϴ�.
		RotateSquare();
		// ��� �����ڵ� �� �ⱸ�� ȸ����ŵ�ϴ�.
		RotateTravelerAndExit();
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << ans << "\n";
	cout << exits.first << " " << exits.second;
}

#endif