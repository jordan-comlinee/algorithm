#include <bits/stdc++.h>
using namespace std;

struct Atom {
	int x;
	int y;
	int dir;
	int k;
	bool live;
	Atom(int x, int y, int dir, int k, bool live = true) : x(x), y(y), dir(dir), k(k), live(live) {}
};

const int SIZE = 4001;
int T, N, x, y, dir, K;
int result = 0;
vector<Atom> atoms;
int board[SIZE][SIZE];
vector<pair<int, int>> deleteAtoms;

// 상(0) 하(1) 좌(2) 우(3)
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void inputData() {
	atoms.clear();
	memset(board, 0, sizeof(board));
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y >> dir >> K;
		int tx = (x + 1000) * 2;
		int ty = (y + 1000) * 2;
		atoms.push_back(Atom(tx, ty, dir, K));
		board[ty][tx]++;
	}
}

int atomExplosion() {
	int energySum = 0;
	int remain = N;

	while (remain > 0) {
		deleteAtoms.clear();

		// 1. 이동
		for (auto& atom : atoms) {
			if (!atom.live) continue;

			// 이동 전 위치 -1
			board[atom.y][atom.x]--;

			atom.x += dx[atom.dir];
			atom.y += dy[atom.dir];

			// 범위 밖으로 나간 원자 소멸
			if (atom.x < 0 || atom.x >= SIZE || atom.y < 0 || atom.y >= SIZE) {
				atom.live = false;
				--remain;
				continue;
			}

			// 이동 후 위치 +1
			board[atom.y][atom.x]++;
		}

		// 2. 충돌 체크
		for (auto& atom : atoms) {
			if (!atom.live) continue;

			if (board[atom.y][atom.x] >= 2) {
				// 충돌 위치 기록
				deleteAtoms.push_back({ atom.y, atom.x });
			}
		}

		// 3. 충돌 처리
		for (auto& pos : deleteAtoms) {
			int y = pos.first, x = pos.second;

			for (auto& atom : atoms) {
				if (!atom.live) continue;
				if (atom.x == x && atom.y == y) {
					energySum += atom.k;
					atom.live = false;
					--remain;
				}
			}

			// 충돌 지점 초기화
			board[y][x] = 0;
		}
	}

	return energySum;
}

void solution() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		result = 0;
		inputData();
		result = atomExplosion();
		cout << "#" << t << " " << result << "\n";
	}
}

int main() {
	solution();
}
