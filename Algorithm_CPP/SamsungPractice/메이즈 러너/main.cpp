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
// 미로의 크기, 참가자 수, 게임 시간
int N, M, K, x, y;
// 이동 거리 합
int pMove = 0;
int board[MAX][MAX];
vector<pair<int, int>> participants;
pair<int, int> exitPoint;
// 상, 하, 좌, 우의 범위
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

// 1초마다 참가자는 한칸씩 움직입니다.
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

// 참가자가 이동을 끝냈으면, 참가자와 미로 정사각형이 가장 작은 것을 구합니다.
Square getSmallest() {
	for (int sz = 2; sz <= N; sz++) {
		for (int x1 = 1; x1 <= N - sz + 1; x1++) {
			for (int y1 = 1; y1 <= N - sz + 1; y1++) {
				int x2 = x1 + sz - 1;
				int y2 = y1 + sz - 1;

				// 출구가 포함되어 있지 않으면 스킵
				if (!(x1 <= exitPoint.first && exitPoint.first <= x2 &&
					y1 <= exitPoint.second && exitPoint.second <= y2)) {
					continue;
				}

				// 한 명 이상의 참가자가 포함되어 있는지 확인
				bool isTravelerIn = false;
				for (int l = 0; l < participants.size(); l++) {
					int tx = participants[l].first;
					int ty = participants[l].second;

					// 출구에 있는 참가자는 제외
					if (tx == exitPoint.first && ty == exitPoint.second) continue;

					if (x1 <= tx && tx <= x2 && y1 <= ty && ty <= y2) {
						isTravelerIn = true;
						break;
					}
				}

				if (isTravelerIn) {
					return Square(x1, y1, sz - 1);  // sz-1은 정사각형의 한 변 거리
				}
			}
		}
	}

	// 못 찾은 경우 - 존재하지 않는 값 리턴
	return Square(-1, -1, -1);
}


// 미로가 회전합니다.
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

// 참가자의 위치와 출구의 위치를 업데이트합니다.
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
		// 1초마다 참가자는 한칸씩 움직입니다.
		participantsMove();
		updateInfo();
		//printInfo();
		if (participants.size() == 0) break;
		// 참가자가 이동을 끝냈으면, 참가자와 미로 정사각형이 가장 작은 것을 구합니다.
		Square s = getSmallest();
		// 미로가 회전합니다.
		rotateSquare(s);
		// 참가자의 위치와 출구의 위치가 모두 바뀌었으므로, 그 정보를 업데이트합니다.
		updateInfo();
		// 모든 참가자가 탈출에 성공하면, 게임이 끝납니다.
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

// 모든 벽들의 상태를 기록해줍니다.
int board[MAX_N + 1][MAX_N + 1];

// 회전의 구현을 편하게 하기 위해 2차원 배열을 하나 더 정의해줍니다.
int next_board[MAX_N + 1][MAX_N + 1];

// 참가자의 위치 정보를 기록해줍니다.
pair<int, int> traveler[MAX_N + 1];

// 출구의 위치 정보를 기록해줍니다.
pair<int, int> exits;

// 정답(모든 참가자들의 이동 거리 합)을 기록해줍니다.
int ans;

// 회전해야 하는 최소 정사각형을 찾아 기록해줍니다.
int sx, sy, square_size;

// 모든 참가자를 이동시킵니다.
void MoveAllTraveler() {
	// m명의 모든 참가자들에 대해 이동을 진행합니다.
	for (int i = 1; i <= m; i++) {
		// 이미 출구에 있는 경우 스킵합니다.
		if (traveler[i].first == exits.first && traveler[i].second == exits.second)
			continue;

		// 행이 다른 경우 행을 이동시켜봅니다.
		if (traveler[i].first != exits.first) {
			int nx = traveler[i].first;
			int ny = traveler[i].second;

			if (exits.first > nx) nx++;
			else nx--;

			// 벽이 없다면 행을 이동시킬 수 있습니다.
			// 이 경우 행을 이동시키고 바로 다음 참가자로 넘어갑니다.
			if (!board[nx][ny]) {
				traveler[i].first = nx;
				traveler[i].second = ny;
				ans++;
				continue;
			}
		}

		// 열이 다른 경우 열을 이동시켜봅니다.
		if (traveler[i].second != exits.second) {
			int nx = traveler[i].first;
			int ny = traveler[i].second;

			if (exits.second > ny) ny++;
			else ny--;

			// 벽이 없다면 행을 이동시킬 수 있습니다.
			// 이 경우 열을 이동시킵니다.
			if (!board[nx][ny]) {
				traveler[i].first = nx;
				traveler[i].second = ny;
				ans++;
				continue;
			}
		}
	}
}

// 한 명 이상의 참가자와 출구를 포함한 가장 작은 정사각형을 찾습니다.
void FindMinimumSquare() {
	// 가장 작은 정사각형부터 모든 정사각형을 만들어봅니다.
	for (int sz = 2; sz <= n; sz++) {
		// 가장 좌상단 r 좌표가 작은 것부터 하나씩 만들어봅니다.
		for (int x1 = 1; x1 <= n - sz + 1; x1++) {
			// 가장 좌상단 c 좌표가 작은 것부터 하나씩 만들어봅니다.
			for (int y1 = 1; y1 <= n - sz + 1; y1++) {
				int x2 = x1 + sz - 1;
				int y2 = y1 + sz - 1;

				// 만약 출구가 해당 정사각형 안에 없다면 스킵합니다.
				if (!(x1 <= exits.first && exits.first <= x2 && y1 <= exits.second && exits.second <= y2)) {
					continue;
				}

				// 한 명 이상의 참가자가 해당 정사각형 안에 있는지 판단합니다.
				bool is_traveler_in = false;
				for (int l = 1; l <= m; l++) {
					if (x1 <= traveler[l].first && traveler[l].first <= x2 && y1 <= traveler[l].second && traveler[l].second <= y2) {
						// 출구에 있는 참가자는 제외합니다.
						if (!(traveler[l].first == exits.first && traveler[l].second == exits.second)) {
							is_traveler_in = true;
						}
					}
				}

				// 만약 한 명 이상의 참가자가 해당 정사각형 안에 있다면
				// sx, sy, sqaure_size 정보를 갱신하고 종료합니다.
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

// 정사각형 내부의 벽을 회전시킵니다.
void RotateSquare() {
	// 우선 정사각형 안에 있는 벽들을 1 감소시킵니다.
	for (int x = sx; x < sx + square_size; x++)
		for (int y = sy; y < sy + square_size; y++) {
			if (board[x][y]) board[x][y]--;
		}

	// 정사각형을 시계방향으로 90' 회전합니다.
	for (int x = sx; x < sx + square_size; x++)
		for (int y = sy; y < sy + square_size; y++) {
			// Step 1. (sx, sy)를 (0, 0)으로 옮겨주는 변환을 진행합니다. 
			int ox = x - sx, oy = y - sy;
			// Step 2. 변환된 상태에서는 회전 이후의 좌표가 (x, y) -> (y, square_n - x - 1)가 됩니다.
			int rx = oy, ry = square_size - ox - 1;
			// Step 3. 다시 (sx, sy)를 더해줍니다.
			next_board[rx + sx][ry + sy] = board[x][y];
		}

	// next_board 값을 현재 board에 옮겨줍니다.
	for (int x = sx; x < sx + square_size; x++)
		for (int y = sy; y < sy + square_size; y++) {
			board[x][y] = next_board[x][y];
		}
}

// 모든 참가자들 및 출구를 회전시킵니다.
void RotateTravelerAndExit() {
	// m명의 참가자들을 모두 확인합니다.
	for (int i = 1; i <= m; i++) {
		int x = traveler[i].first;
		int y = traveler[i].second;
		// 해당 참가자가 정사각형 안에 포함되어 있을 때에만 회전시킵니다.
		if (sx <= x && x < sx + square_size && sy <= y && y < sy + square_size) {
			// Step 1. (sx, sy)를 (0, 0)으로 옮겨주는 변환을 진행합니다. 
			int ox = x - sx, oy = y - sy;
			// Step 2. 변환된 상태에서는 회전 이후의 좌표가 (x, y) -> (y, square_n - x - 1)가 됩니다.
			int rx = oy, ry = square_size - ox - 1;
			// Step 3. 다시 (sx, sy)를 더해줍니다.
			traveler[i] = make_pair(rx + sx, ry + sy);
		}
	}

	// 출구에도 회전을 진행합니다.
	int x = exits.first;
	int y = exits.second;
	if (sx <= x && x < sx + square_size && sy <= y && y < sy + square_size) {
		// Step 1. (sx, sy)를 (0, 0)으로 옮겨주는 변환을 진행합니다. 
		int ox = x - sx, oy = y - sy;
		// Step 2. 변환된 상태에서는 회전 이후의 좌표가 (x, y) -> (y, square_n - x - 1)가 됩니다.
		int rx = oy, ry = square_size - ox - 1;
		// Step 3. 다시 (sx, sy)를 더해줍니다.
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
		// 모든 참가자를 이동시킵니다.
		MoveAllTraveler();

		// 모든 사람이 출구로 탈출했는지 판단합니다.
		bool is_all_escaped = true;
		for (int i = 1; i <= m; i++) {
			if (!(traveler[i].first == exits.first && traveler[i].second == exits.second)) {
				is_all_escaped = false;
			}
		}

		// 만약 모든 사람이 출구로 탈출했으면 바로 종료합니다.
		if (is_all_escaped) break;

		// 한 명 이상의 참가자와 출구를 포함한 가장 작은 정사각형을 찾습니다.
		FindMinimumSquare();

		// 정사각형 내부의 벽을 회전시킵니다.
		RotateSquare();
		// 모든 참가자들 및 출구를 회전시킵니다.
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