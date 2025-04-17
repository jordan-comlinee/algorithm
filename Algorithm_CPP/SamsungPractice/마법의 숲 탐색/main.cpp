#include <bits/stdc++.h>
using namespace std;

struct Golem {
	int x;
	int y;
	int d;
	Golem() : x(0), y(0), d(0) {}
	Golem(int x, int y, int d) : x(x), y(y), d(d) {};
};

const int MAX = 75;
const int GOLEMS = 1000;
const int G = 1;
const int X = -1;
// ���� ũ�� R, C, ������ �� K, �� ��� �� c, �ⱸ ���� ���� d
int R, C, K, ci, di, result;
vector<Golem> golems;
set<pair<int, int>> exitSet;
int forest[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { false };
// d�� ����. ��(0) ��(1) ��(2) ��(3)
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void inputData();
bool putGolem(Golem &golem, int num);
int fairyMove(Golem golem);
void clearForest();
void solution();

int main() {
	inputData();
	solution();
	cout << result << endl;
}


void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> K;
	golems.resize(K);
	for (int k = 0; k < K; ++k) {
		cin >> ci >> di;
		golems[k] = Golem(1, ci, di);
	}

}

bool putGolem(Golem& golem, int num) {
	while (true) {
		// [1] �������� �� ĭ ������ �� �ִ��� Ȯ��
		if (golem.x + 2 < MAX &&
			golem.y - 1 >= 0 && golem.y + 1 < MAX &&
			forest[golem.x + 1][golem.y - 1] + forest[golem.x + 2][golem.y] + forest[golem.x + 1][golem.y + 1] == 0) {
			golem.x++;
		}
		// [2] �������� ȸ���ϸ� �� ĭ ������ �� �ִ��� Ȯ��
		else if (golem.x - 1 >= 0 && golem.x + 2 < MAX &&
			golem.y - 2 >= 0 &&
			forest[golem.x - 1][golem.y - 1] + forest[golem.x][golem.y - 2] +
			forest[golem.x + 1][golem.y - 1] + forest[golem.x + 1][golem.y - 2] +
			forest[golem.x + 2][golem.y - 1] == 0) {
			golem.x++;
			golem.y--;
			golem.d = (golem.d + 3) % 4; // ���� ȸ��
		}
		// [3] �������� ȸ���ϸ� �� ĭ ������ �� �ִ��� Ȯ��
		else if (golem.x - 1 >= 0 && golem.x + 2 < MAX &&
			golem.y + 2 < MAX &&
			forest[golem.x - 1][golem.y + 1] + forest[golem.x][golem.y + 2] +
			forest[golem.x + 1][golem.y + 1] + forest[golem.x + 1][golem.y + 2] +
			forest[golem.x + 2][golem.y + 1] == 0) {
			golem.x++;
			golem.y++;
			golem.d = (golem.d + 1) % 4; // ���� ȸ��
		}
		else {
			break;
		}
	}

	// [4] ���� �ʹ� ���� �������� ����
	if (golem.x < 4) {
		return false;
	}

	// [5] ��� üũ �� �� ��ġ
	if (golem.x - 1 >= 0 && golem.x + 1 < MAX &&
		golem.y - 1 >= 0 && golem.y + 1 < MAX) {

		forest[golem.x][golem.y] = num;
		forest[golem.x - 1][golem.y] = num;
		forest[golem.x + 1][golem.y] = num;
		forest[golem.x][golem.y - 1] = num;
		forest[golem.x][golem.y + 1] = num;

		// �ⱸ ��ġ ��� (���⵵ ��� Ȯ��)
		int ex = golem.x + dx[golem.d];
		int ey = golem.y + dy[golem.d];
		if (ex >= 0 && ex < MAX && ey >= 0 && ey < MAX) {
			exitSet.insert({ ex, ey });
		}

		return true;
	}

	return false;
}


int fairyMove(Golem golem) {
	queue<pair<int, int>> q;
	int maxI = 0;
	fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);
	q.push({ golem.x, golem.y });
	visited[golem.x][golem.y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		maxI = max(maxI, x);
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx <= R + 2 && ny >= 1 && ny <= C + 1 && !visited[nx][ny] &&
				(forest[nx][ny] == forest[x][y] ||
					(exitSet.count({ x, y }) && forest[nx][ny] == forest[x][y]))) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
	return maxI - 2;
}

void clearForest(){
	memset(&forest, 0, sizeof(forest));
	exitSet.clear();
}

void solution() {
	int num = 2;
	for (int i = 0; i < K; ++i) {

		// ���� ��������.
		// ���� ������ ��, ���� ���� �� �����ϸ� ������ ��������.
		// ���� ������ ��, ���� ���� ���� ���ߴٸ� ���� �������.
		if (putGolem(golems[i], num)) {
			//cout << "fairy move" << endl;
			result += fairyMove(golems[i]);
			cout << fairyMove(golems[i]) << endl;
			num++;
		}
		else {
			//cout << "clear forest" << endl;
			clearForest();
			num = 2;
		}
	}
}