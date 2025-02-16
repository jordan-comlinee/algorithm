#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;


int N, M, K; // 세로, 가로, 이동 횟수
int maps[MAX][MAX];	// 지도
int score_map[MAX][MAX] = { 0 };
int result=0;	// B*C, 최종 값
pair<int, int> current_dice = {0, 0};
int dice_dir = 0;	// 주사위의 방향
// ++하면 시계방향 회전, --하면 반시계방향 회전
// 동, 남, 서, 북
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int current_top = 1;
// 동, 남, 서, 북 방향으로 갔을 때 주사위의 앞면 위치
int dice_dir_value[7][4] = { 
	{0, 0, 0, 0}, 
	{4, 5, 3, 2}, 
	{6, 3, 1, 4}, 
	{1, 5, 6, 2}, 
	{6, 2, 1, 5}, 
	{4, 6, 3, 1}, 
	{4, 2, 3, 5} };
int dice_under_value[7] = { 0, 6, 5, 4, 3, 2, 1 };


void input_data();
int get_score(int x, int y);
void get_score_map();
//int get_dice_under_value();
int roll_dice();	// 주사위가 이동 한번 했을 때 점수를 얻는다.
void solution();
bool isInRange(int nx, int ny);
void print_info(int n);

int main() {
	input_data();
	//cout << endl;
	solution();
	cout << result << endl;
}

void input_data() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> maps[i][j];
		}
	}
}

bool isInRange(int nx, int ny) {
	return (nx >= 0 && nx < N && ny >= 0 && ny < M);
}

int get_score(int x, int y) {
	int sum_score = maps[x][y];
	bool visited[MAX][MAX] = { false };
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (isInRange(nx, ny) && !visited[nx][ny] && maps[nx][ny] == maps[x][y]) {
				visited[nx][ny] = true;
				sum_score += maps[x][y];
				q.push(make_pair(nx, ny));
			}
		}
	}
	return sum_score;
}

void get_score_map() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			score_map[i][j] = get_score(i, j);
		}
	}
}
/*
int get_dice_under_value() {
	return 0;
}
*/

int roll_dice() {
	int A = 0, B = 0; // 주사위의 아랫면, 주사위가 있는 칸에 있는 정수
	int score = 0;
	// 주사위가 이동 방향으로 한 칸 굴러간다.
	int nx = current_dice.first + dx[dice_dir];
	int ny = current_dice.second + dy[dice_dir];
	// 만약, 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다.
	if (!isInRange(nx, ny)) {
		dice_dir = (dice_dir + 2) % 4;
		nx = current_dice.first + dx[dice_dir];
		ny = current_dice.second + dy[dice_dir];
	}
	current_dice = make_pair(nx, ny);
	current_top = dice_dir_value[current_top][dice_dir];
	B = maps[nx][ny];
	A = dice_under_value[current_top];
	// 주사위가 도착한 칸 (x, y)에 대한 점수를 획득한다.
	score = score_map[nx][ny];

	// 주사위의 아랫면에 있는 정수 A와 주사위가 있는 칸 (x, y)에 있는 정수 B를 비교해 이동 방향을 결정한다.
	if (A > B) {
		dice_dir = (dice_dir + 1) % 4;	// 시계 방향 회전
	}
	else if (A < B) {
		dice_dir = (dice_dir + 3) % 4;	// 반시계 방향 회전

	}

	//cout << "A : " << A << " B : " << B << endl;

	return score;
}

void print_info(int n) {
	cout << "case : " << n+1 << endl;
	cout << "current dice is at " << current_dice.first+1 << ", " << current_dice.second+1 << endl;
	cout << "and the dice is facing to " << dice_dir << endl;
	cout << "top of the dice is " << current_top << endl;
	cout << "current score is " << result << endl;
	cout << endl;
}

void solution() {
	get_score_map();
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < M; ++j) {
	//		cout << score_map[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	for (int k = 0; k < K; ++k) {
		result += roll_dice();
		//print_info(k);
	}
	return;
}