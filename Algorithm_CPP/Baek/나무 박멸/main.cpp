#include <bits/stdc++.h>
using namespace std;

const int MAX = 21;
int n, m, K, c; // ������ ũ��, �ڸ� ���� �Ⱓ, Ȯ�� ����, ������ �ܿ� ��
int board[MAX][MAX];	// ���� ����
int killBoard[MAX][MAX];// �������� �ִ� ��ġ
int result;		// �ڸ��� ������ �׷� ��
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cx[2] = { 1, -1 };
int cy[2] = { 1, -1 };
typedef struct _tree {
	int val;
	int first;
	int second;
}Tree;

bool isInRange(int x, int y);
void inputData();
void printData();
void growReproduce();
int getAvailableKill(int x, int y);
void kill();

int main() {
	inputData();
	for (int i = 0; i < m; ++i) {
		growReproduce();
		kill();
		//cout << "========" << endl;
		//printData();
	}
	cout << result << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> K >> c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}
}

bool isInRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n && board[x][y] != -1);
}

void printData() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
// ������ �װ��� ĭ�� �� ��ŭ ������ �����Ѵ�. ������ ��� �������� ���ÿ� �Ͼ��.
// ������ �־��� �������� ������ 4���� ĭ �� ��, �ٸ� ����, ������ ��� ���� ĭ�� �����Ѵ�.
// �� ĭ�� ���� �׷� ������ �� ������ ������ ĭ�� ������ŭ �������� �׷� ����ŭ ������ �ȴ�.
// ������ ������ ��� �������� ���ÿ� �Ͼ��.
void growReproduce() {
	queue<Tree> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// ĭ�� ������ �ִ��� Ȯ���Ѵ�.
			if (board[i][j] > 0) {
				int growth = 0, noneBlock = 0;
				vector<pair<int, int>> none;
				// �װ� ĭ�� ������ �ִ� �� Ȯ���Ѵ�.
				for (int k = 0; k < 4; ++k) {
					if (isInRange(i + dx[k], j+dy[k])) {
						if (board[i + dx[k]][j + dy[k]] > 0) growth++;
						else if (board[i + dx[k]][j + dy[k]] == 0) {
							noneBlock++;
							none.push_back({ i + dx[k], j + dy[k] });
						}
					}
				}
				board[i][j] += growth;
				// �� ĭ�� ���� �׷� ������ �� ������ ������ ĭ�� ������ŭ �������� �׷� ����ŭ ������ �ȴ�.
				if (noneBlock > 0) {
					int reproduceVal = board[i][j] / noneBlock;
					// ������ �Ǵ� �κ��� ť�� �����Ѵ�.
					for (auto n : none) {
						q.push({ reproduceVal, n.first, n.second });
					}
				}
				
			}
		}
	}
	// �Ѳ����� ������ �����Ѵ�.
	while (!q.empty()) {
		Tree newTree = q.front();
		q.pop();
		if (killBoard[newTree.first][newTree.second] == 0) {
			board[newTree.first][newTree.second] += newTree.val;
		}
	}
}

int getAvailableKill(int x, int y) {
	int killedTree = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			int k = 1;
			while (isInRange(x + cx[i] * k, y + cy[j] * k) && board[x + cx[i] * k][y + cy[j] * k] >= 0 && k <= K) {
				killedTree += board[x + cx[i] * k][y + cy[j] * k];
				k++;
			}
		}
	}
	return killedTree;
}

// �� ĭ ��, �������� �ѷ��� �� ������ ���� ���� �۸�Ǵ� ĭ�� �������� �Ѹ���.
// ������ ���� ĭ�� �������� �Ѹ��� �ڸ�Ǵ� ������ ���� ���� ���·� ������.
// �������� �ѷ��� ĭ���� c�� ��ŭ �������� �����ִ�.
// �������� �ѷ��� �ִ� ���� �ٽ� �Ѹ���, c�� ���� �������� ���´�.
void kill() {
	// �������� �Ѹ� ��ġ�� �����Ѵ�.
	Tree killSpot = { 0, 0, 0 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// �������� ���ŵȴ�.
			killBoard[i][j] = killBoard[i][j] > 0 ? killBoard[i][j] - 1 : 0;
			int availableKill = 0;
			if (board[i][j] > 0) {
				availableKill = getAvailableKill(i, j);
				if (killSpot.val < availableKill + board[i][j]) {
					killSpot.val = availableKill + board[i][j];
					killSpot.first = i; killSpot.second = j;
				}
			}
			//cout << availableKill+board[i][j] << " ";
			
		}
		//cout << endl;
	}
	//cout << killSpot.val << " and x: " << killSpot.first << " y: " << killSpot.second << endl;
	// �������� �Ѹ� ��, X�ڷ� c ��ŭ�� �������� ���´�.
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			int k = 1;
			while (isInRange(killSpot.first + cx[i] * k, killSpot.second + cy[j] * k) && board[killSpot.first + cx[i] * k][killSpot.second + cy[j] * k] >= 0 && k <= K) {
				board[killSpot.first + cx[i] * k][killSpot.second + cy[j] * k] = 0;
				killBoard[killSpot.first + cx[i] * k][killSpot.second + cy[j] * k] = c;
				k++;
			}
		}
	}
	board[killSpot.first][killSpot.second] = 0;
	killBoard[killSpot.first][killSpot.second] = c;
	result += killSpot.val;
}