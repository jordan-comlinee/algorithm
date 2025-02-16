#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;


int N, M, K; // ����, ����, �̵� Ƚ��
int maps[MAX][MAX];	// ����
int score_map[MAX][MAX] = { 0 };
int result=0;	// B*C, ���� ��
pair<int, int> current_dice = {0, 0};
int dice_dir = 0;	// �ֻ����� ����
// ++�ϸ� �ð���� ȸ��, --�ϸ� �ݽð���� ȸ��
// ��, ��, ��, ��
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int current_top = 1;
// ��, ��, ��, �� �������� ���� �� �ֻ����� �ո� ��ġ
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
int roll_dice();	// �ֻ����� �̵� �ѹ� ���� �� ������ ��´�.
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
	int A = 0, B = 0; // �ֻ����� �Ʒ���, �ֻ����� �ִ� ĭ�� �ִ� ����
	int score = 0;
	// �ֻ����� �̵� �������� �� ĭ ��������.
	int nx = current_dice.first + dx[dice_dir];
	int ny = current_dice.second + dy[dice_dir];
	// ����, �̵� ���⿡ ĭ�� ���ٸ�, �̵� ������ �ݴ�� �� ���� �� ĭ ��������.
	if (!isInRange(nx, ny)) {
		dice_dir = (dice_dir + 2) % 4;
		nx = current_dice.first + dx[dice_dir];
		ny = current_dice.second + dy[dice_dir];
	}
	current_dice = make_pair(nx, ny);
	current_top = dice_dir_value[current_top][dice_dir];
	B = maps[nx][ny];
	A = dice_under_value[current_top];
	// �ֻ����� ������ ĭ (x, y)�� ���� ������ ȹ���Ѵ�.
	score = score_map[nx][ny];

	// �ֻ����� �Ʒ��鿡 �ִ� ���� A�� �ֻ����� �ִ� ĭ (x, y)�� �ִ� ���� B�� ���� �̵� ������ �����Ѵ�.
	if (A > B) {
		dice_dir = (dice_dir + 1) % 4;	// �ð� ���� ȸ��
	}
	else if (A < B) {
		dice_dir = (dice_dir + 3) % 4;	// �ݽð� ���� ȸ��

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