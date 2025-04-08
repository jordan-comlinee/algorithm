#include <bits/stdc++.h>
using namespace std;

struct Atom {
	int x;
	int y;
	int dir;
	int k;
	bool live;
	Atom(int x, int y, int dir, int k, bool live) : x(x), y(y), dir(dir), k(k), live(live) {}
};

const int MAX = 4000;
const int MIN = 0;
// 테스트케이스의 수, 원자들의 수, 원자들의 보유 에너지, 입력 방향
int T, N, K, x, y, dir;
int result = 0;
vector<Atom> atoms;
int conflict[MAX + 1][MAX + 1];

// 상(0) 하(1) 좌(2) 우(3)
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void inputData();
void solution();
void atomExplosion();

int main() {
	solution();
}


//입력의 가장 첫 줄에는 총 테스트 케이스의 개수 T가 주어진다.
//그 다음 줄부터는 각 테스트 케이스가 주어진다.각 테스트 케이스의 첫째 줄에는 원자들의 수 N이 주어진다.
//다음 N개의 줄에는 원자들의 x 위치, y 위치, 이동 방향, 보유 에너지 K가 주어진다.
//원자들의 이동 방향은 상(0), 하(1), 좌(2), 우(3)로 주어진다.
void inputData() {
	cin >> N;
	for (int n = 0; n < N; ++n) {
		cin >> x >> y >> dir >> K;
		atoms.push_back(Atom((x + 1000) * 2, (y + 1000) * 2, dir, K, true));
	}
}
// 원자 소멸 시뮬레이션을 진행한다.
// 각 원자들이 먼저 이동을 수행한다.
// 원자들 중, 범위 밖으로 벗어난 원자들은 끼지 않는다.
// 원자들 중, 범위 내의 원자들에서 충돌한 원자들은 없앤다.
// 소멸까지 완료된 원자들은 없앤다.
void atomExplosion() {
	bool move = false;
	while (true) {
		move = false;

		// 이동
		for (int i = 0; i < atoms.size(); ++i) {
			
			if (!atoms[i].live) continue;
			conflict[atoms[i].x][atoms[i].y] = 0;
			atoms[i].x += dx[atoms[i].dir];
			atoms[i].y += dy[atoms[i].dir];

			if (atoms[i].x < MIN || atoms[i].x > MAX || atoms[i].y < MIN || atoms[i].y > MAX) {
				atoms[i].live = false; // 범위 밖으로 나가면 사망
				//atoms[i].k = 0;
				continue;
			}
			conflict[atoms[i].x][atoms[i].y] += atoms[i].k;
			move = true;
		}

		// 충돌 처리
		for (int i = 0; i < atoms.size(); ++i) {
			if (atoms[i].live && conflict[atoms[i].x][atoms[i].y] != atoms[i].k) {
				result += conflict[atoms[i].x][atoms[i].y];
				conflict[atoms[i].x][atoms[i].y] = 0;
				//atoms[i].k = 0;
				atoms[i].live = false;
			}
		}

		if (!move) break;
	}
}

void solution() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		inputData();
		atomExplosion();
		cout << "#" << t << " " << result << endl;
		result = 0;
	}
}