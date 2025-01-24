#include <bits/stdc++.h>
using namespace std;
// [1] ���̻� ���� �� �ִ� ����Ⱑ ������ ���ٸ� �Ʊ� ���� ���� ���� ������ ��û�Ѵ�.
// [2] ���� �� �ִ� ����Ⱑ 1�������, �� ����⸦ ������ ����.
// [3] ���� �ִ� �����, ���ʿ� �ִ� ����� ������ �Դ´�. -> priority queue

// [4] �ڽ��� ũ�⺸�� ū ����Ⱑ �ִ� ĭ�� ������ �� ����.
// [5] �ڽŰ� ���� ũ���� ������ ������ �������� ������ �� �ִ�.
// [6] �ڽź��� ���� ũ���� ������ ���� �� �ְ�, ������ �� �ִ�.

// [7] �ڽ��� ũ��� ���� Ƚ���� ����⸦ ������, ũ�Ⱑ 1 Ŀ����.

class SharkInfo {
public:
	pair<int, int> location;
	int time;
	SharkInfo(pair<int, int>curr) : location(curr), time(0) {};
	SharkInfo(pair<int, int>curr, int time) : location(curr), time(time) {};
};

// [3]
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
int N, M;	// N*Nũ��, M���� �����
int result = 0;
int shark_size = 2;	// �Ʊ� ����� ũ��
int shark_point = 2;// �Ʊ� �� �ڶ����� ���� ����ġ
vector<vector<int>> board;	// N*N ����
pair<int, int> shark_location;

void input_data();
void print_board();
SharkInfo bfs(pair<int, int> shark_locate);
void solution();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input_data();
	solution();

	cout << result << endl;
	return 0;
}


void input_data() {
	cin >> N;
	board = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				shark_location.first = i;
				shark_location.second = j;
			}
		}
	}
}

void print_board() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
SharkInfo bfs(pair<int, int> shark_locate) {
	SharkInfo info(shark_locate, 0);
	vector<vector<int>> visited(N, vector<int>(N, 0));
	priority_queue<pair<int, int>> q;
	q.push(shark_locate);
	while (!q.empty()) {
		int x = q.top().first;
		int y = q.top().second;
		int count = visited[x][y];
		q.pop();
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// �� ���� ���� �ȿ� �ְ�
			if (0 <= nx && nx < N && 0 <= ny && ny < N && visited[nx][ny] == 0) {
				// ���̰� ���� ũ��
				if (board[nx][ny] > shark_size) {
					continue;
				}
				else if (board[nx][ny] != 0 && board[nx][ny] < shark_size) {
					//cout << "2" << endl;
					info.location = { nx, ny };
					info.time = count + 1;
					--shark_point;
					return info;
				}
				else {
					//cout << "3" << endl;
					q.push({ nx, ny });
					visited[nx][ny] = count + 1;
				}
			}
		}
	}
	return info;
}

void solution() {
	SharkInfo curr_info(shark_location);
	while (true) {

		board[curr_info.location.first][curr_info.location.second] = 0;
		curr_info = bfs(curr_info.location);
		//cout << curr_info.location.first << " " << curr_info.location.second << endl;
		//cout << curr_info.time << endl;
		if (curr_info.time == 0) {
			return;
		}
		if (shark_point == 0) {
			++shark_size;
			shark_point = shark_size;
		}
		result += curr_info.time;

	}
}