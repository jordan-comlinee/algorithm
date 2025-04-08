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
// �׽�Ʈ���̽��� ��, ���ڵ��� ��, ���ڵ��� ���� ������, �Է� ����
int T, N, K, x, y, dir;
int result = 0;
vector<Atom> atoms;
int conflict[MAX + 1][MAX + 1];

// ��(0) ��(1) ��(2) ��(3)
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void inputData();
void solution();
void atomExplosion();

int main() {
	solution();
}


//�Է��� ���� ù �ٿ��� �� �׽�Ʈ ���̽��� ���� T�� �־�����.
//�� ���� �ٺ��ʹ� �� �׽�Ʈ ���̽��� �־�����.�� �׽�Ʈ ���̽��� ù° �ٿ��� ���ڵ��� �� N�� �־�����.
//���� N���� �ٿ��� ���ڵ��� x ��ġ, y ��ġ, �̵� ����, ���� ������ K�� �־�����.
//���ڵ��� �̵� ������ ��(0), ��(1), ��(2), ��(3)�� �־�����.
void inputData() {
	cin >> N;
	for (int n = 0; n < N; ++n) {
		cin >> x >> y >> dir >> K;
		atoms.push_back(Atom((x + 1000) * 2, (y + 1000) * 2, dir, K, true));
	}
}
// ���� �Ҹ� �ùķ��̼��� �����Ѵ�.
// �� ���ڵ��� ���� �̵��� �����Ѵ�.
// ���ڵ� ��, ���� ������ ��� ���ڵ��� ���� �ʴ´�.
// ���ڵ� ��, ���� ���� ���ڵ鿡�� �浹�� ���ڵ��� ���ش�.
// �Ҹ���� �Ϸ�� ���ڵ��� ���ش�.
void atomExplosion() {
	bool move = false;
	while (true) {
		move = false;

		// �̵�
		for (int i = 0; i < atoms.size(); ++i) {
			
			if (!atoms[i].live) continue;
			conflict[atoms[i].x][atoms[i].y] = 0;
			atoms[i].x += dx[atoms[i].dir];
			atoms[i].y += dy[atoms[i].dir];

			if (atoms[i].x < MIN || atoms[i].x > MAX || atoms[i].y < MIN || atoms[i].y > MAX) {
				atoms[i].live = false; // ���� ������ ������ ���
				//atoms[i].k = 0;
				continue;
			}
			conflict[atoms[i].x][atoms[i].y] += atoms[i].k;
			move = true;
		}

		// �浹 ó��
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