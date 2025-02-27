#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;
const int NOTCLEANED = 0;
const int WALL = 1;
const int CLEANED = -1;
int N, M;
// �κ�û�ұ��� ����
int r, c, d;
// �κ� û�ұ��� ���� ��ġ
pair<int, int> vacuum;
// ��, ��, ��, ��
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int nx, ny;
int result;
int room[MAX][MAX];

void inputData();
bool isAroundDirty();
bool check(int x, int y, int state);
void solution();


int main() {
	inputData();
	solution();
	cout << result << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	cin >> vacuum.first >> vacuum.second >> d;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> room[i][j];
		}
	}
}
// �ֺ� 4ĭ �������� üũ
bool isAroundDirty() {
	for (int i = 0; i < 4; ++i){
		nx = vacuum.first + dx[i];
		ny = vacuum.second + dy[i];
		if (check(nx, ny, NOTCLEANED)) {
			return true;
		}
	}
	return false;
}

bool check(int x, int y, int state) {
	return (room[x][y] == state);
}

void solution() {
	while (1) {
		//���� ĭ�� ���� û�ҵ��� ���� ���, ���� ĭ�� û���Ѵ�.
		if (room[vacuum.first][vacuum.second] == NOTCLEANED) {
			//cout << "clean the room" << endl;
			result += 1;
			room[vacuum.first][vacuum.second] = CLEANED;
		}

		// ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �ִ� ���
		if (isAroundDirty()) {
			//cout << "Not clean" << endl;
			while (1) {
				d = (d + 3) % 4;
				nx = vacuum.first + dx[d];
				ny = vacuum.second + dy[d];
				if (room[nx][ny] == NOTCLEANED){
					vacuum = make_pair(nx, ny);
					break;
				}
			}
		}
		// ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� ���� ���
		else {
			//cout << "is clean" << endl;
			nx = vacuum.first - dx[d];
			ny = vacuum.second - dy[d];
			// �ٶ󺸴� ������ ���� ĭ�� ���̶� ������ �� ���ٸ� �۵��� �����.
			if (check(nx, ny, WALL)) {
				return;
			}
			// �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �� �ִٸ� �� ĭ �����ϰ� 1������ ���ư���.
			vacuum = make_pair(nx, ny);
		}

		

	}
}