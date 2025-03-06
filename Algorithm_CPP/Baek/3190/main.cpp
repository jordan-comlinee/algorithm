#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;	// ���� �� ��� ���� �ִ밪
const int APPLE = 1;
int N, K, L, X;			// ������ ũ��, ����� ����, ���� ���� ��ȯ Ƚ��, ���� ��ȯ �ð�
char C;					// ���� ����
int x, y;				// ����� ��ġ �Է�
deque<pair<int, int>> snake;	// ���� ��ġ
deque<pair<int, char>> snakeVec;// ���� ���� ����
int currentSnakeVec = 0;
int board[MAX][MAX];
int result = 0;
// ��->��->��->��
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void inputData();
void solution();
bool canMove(pair<int, int> head);

int main() {
	inputData();
	solution();
	cout << result << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < K; ++i) {
		cin >> x >> y;
		board[x-1][y-1] = APPLE;
	}
	cin >> L;
	for (int i = 0; i < L; ++i) {
		cin >> X >> C;
		snakeVec.push_back({X, C});
	}
	snake.push_front({ 0, 0 });
}
// ���� �Ӹ��� ���̳� �ڱ� �ڽ��� ���� �ε����� �� Ȯ��
bool canMove(pair<int, int> head) {
	if (head.first >= 0 && head.first < N && head.second >= 0 && head.second < N){
		for (auto body : snake) {
			if (head == body) {
				return false; 
			}
		}
		return true;
	}
	return false;
}

void solution() {
	while (true) {
		// �ð��� 1�� �����Ѵ�.
		++result;
		// ���� ���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��.
		pair<int, int> nextHead = snake.front();
		nextHead.first += dx[currentSnakeVec];
		nextHead.second += dy[currentSnakeVec];
		// ���� ���̳� �ڱ��ڽ��� ���� �ε����� ������ ������.
		if (!canMove(nextHead)) {
			break; 
		}
		snake.push_front(nextHead);
		// ���� �̵��� ĭ�� ����� �ִٸ�, 
		if (board[snake.front().first][snake.front().second] == 1) {
			// �� ĭ�� �ִ� ����� ��������
			board[snake.front().first][snake.front().second] = 0;
			// ������ �������� �ʴ´�.
		}
		else {
			// ���� �̵��� ĭ�� ����� ���ٸ�, �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�. ��, �����̴� ������ �ʴ´�.
			snake.pop_back();
		}

		// ���� ������ �ٲ�� �ϴ��� Ȯ���Ѵ�.
		if (!snakeVec.empty() && snakeVec.front().first == result) {
			if (snakeVec.front().second == 'D') {
				currentSnakeVec = (currentSnakeVec + 1) % 4;
			}
			else {
				currentSnakeVec = (currentSnakeVec + 3) % 4;
			}
			snakeVec.pop_front();
		}
		
	}
}