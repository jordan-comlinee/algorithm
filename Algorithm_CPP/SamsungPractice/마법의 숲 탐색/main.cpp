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
// 숲의 크기 R, C, 정령의 수 K, 골렘 출발 열 c, 출구 방향 정보 d
int R, C, K, ci, di, result;
vector<Golem> golems;
set<pair<int, int>> exitSet;
int forest[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { false };
// d의 방향. 북(0) 동(1) 남(2) 서(3)
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
		// [1] 남쪽으로 한 칸 내려갈 수 있는지 확인
		if (golem.x + 2 < MAX &&
			golem.y - 1 >= 0 && golem.y + 1 < MAX &&
			forest[golem.x + 1][golem.y - 1] + forest[golem.x + 2][golem.y] + forest[golem.x + 1][golem.y + 1] == 0) {
			golem.x++;
		}
		// [2] 서쪽으로 회전하며 한 칸 내려갈 수 있는지 확인
		else if (golem.x - 1 >= 0 && golem.x + 2 < MAX &&
			golem.y - 2 >= 0 &&
			forest[golem.x - 1][golem.y - 1] + forest[golem.x][golem.y - 2] +
			forest[golem.x + 1][golem.y - 1] + forest[golem.x + 1][golem.y - 2] +
			forest[golem.x + 2][golem.y - 1] == 0) {
			golem.x++;
			golem.y--;
			golem.d = (golem.d + 3) % 4; // 서쪽 회전
		}
		// [3] 동쪽으로 회전하며 한 칸 내려갈 수 있는지 확인
		else if (golem.x - 1 >= 0 && golem.x + 2 < MAX &&
			golem.y + 2 < MAX &&
			forest[golem.x - 1][golem.y + 1] + forest[golem.x][golem.y + 2] +
			forest[golem.x + 1][golem.y + 1] + forest[golem.x + 1][golem.y + 2] +
			forest[golem.x + 2][golem.y + 1] == 0) {
			golem.x++;
			golem.y++;
			golem.d = (golem.d + 1) % 4; // 동쪽 회전
		}
		else {
			break;
		}
	}

	// [4] 골렘이 너무 위에 멈췄으면 실패
	if (golem.x < 4) {
		return false;
	}

	// [5] 경계 체크 후 골렘 배치
	if (golem.x - 1 >= 0 && golem.x + 1 < MAX &&
		golem.y - 1 >= 0 && golem.y + 1 < MAX) {

		forest[golem.x][golem.y] = num;
		forest[golem.x - 1][golem.y] = num;
		forest[golem.x + 1][golem.y] = num;
		forest[golem.x][golem.y - 1] = num;
		forest[golem.x][golem.y + 1] = num;

		// 출구 위치 등록 (여기도 경계 확인)
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

		// 골렘이 내려간다.
		// 골렘이 내려간 후, 골렘이 들어가는 데 성공하면 정령이 내려간다.
		// 골렘이 내려간 후, 골렘이 만약 들어가지 못했다면 숲이 비워진다.
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