#include<bits/stdc++.h>
using namespace std;
using dt = pair<int, pair<int, int>>;
const int MAX = 10;
// ���� ũ��, ������ ����, �ð�
int N, M, K;
int i, j;
int board[MAX][MAX] = { 0 };
int A[MAX][MAX] = { 0 };
priority_queue<dt, vector<dt>, greater<dt>> tree;
priority_queue<dt> nextTree;
priority_queue<dt> deadTree;
int dx[] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dy[] = { -1, 1, 0, -1, 1, 0, -1, 1 };

void inputData();
void spring();
void summer();
void fall();
void reproduceTree(pair<int, int> position);
bool isInRange(int x, int y);
void winter();
void printData();
void solution();

int main() {
	inputData();
	solution();
	cout << tree.size() << endl;
}


void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fill(&board[0][0], &board[MAX][MAX], 5);
	cin >> N >> M >> K;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	for (i = 0; i < M; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		tree.push(make_pair(z, make_pair(x-1, y-1)));
	}
}
// ������ ������ �ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 �����Ѵ�.
void spring() {
	//cout << "spring start" << endl;
	while (!tree.empty()) {
		int currentTreeSize = tree.top().first;
		pair<int, int> currentTreePos = tree.top().second;
		tree.pop();

		if (board[currentTreePos.first][currentTreePos.second] >= currentTreeSize) {
			board[currentTreePos.first][currentTreePos.second] -= currentTreeSize;
			nextTree.push(make_pair(++currentTreeSize, currentTreePos));
		}
		//����, ���� ����� ������ �ڽ��� ���̸�ŭ ����� ���� �� ���� ������ ����� ���� ���ϰ� ��� �״´�.
		else {
			deadTree.push(make_pair(currentTreeSize, currentTreePos));
		}
	}
	// ��� ���� �������� �ٽ� tree ����Ʈ�� �ִ´�.
	while (!nextTree.empty()) {
		tree.push(nextTree.top());
		nextTree.pop();
	}
	//cout << tree.size() << endl;

}
// �������� ���� ���� ������ ������� ���ϰ� �ȴ�.
void summer() {
	//cout << "summer start" << endl;
	while (!deadTree.empty()) {
		// ������ ���� �������� ���̸� 2�� ���� ���� ������ �ִ� ĭ�� ������� �߰��ȴ�. �Ҽ��� �Ʒ��� ������.
		int deadTreeSize = deadTree.top().first;
		pair<int, int> deadTreePos = deadTree.top().second;
		deadTree.pop();
		board[deadTreePos.first][deadTreePos.second] += deadTreeSize / 2;
	}
}
// �������� ������ �����Ѵ�.
void fall() {
	//cout << "fall start" << endl;
	while (!tree.empty()) {
		int currentTreeSize = tree.top().first;
		pair<int, int> currentTreePos = tree.top().second;
		tree.pop();
		//  �����ϴ� ������ ���̰� 5�� ����̾�� �ϸ�,
		if (currentTreeSize % 5 == 0) {
			//cout << "reproduce" << endl;
			//������ 8���� ĭ�� ���̰� 1�� ������ �����.
			reproduceTree(currentTreePos);
		}

		nextTree.push(make_pair(currentTreeSize, currentTreePos));

	}
	// Ȯ���� �������� �ٽ� tree ����Ʈ�� �ִ´�.
	while (!nextTree.empty()) {
		tree.push(nextTree.top());
		nextTree.pop();
	}
	//cout << tree.size() << endl;
}

void reproduceTree(pair<int, int> position) {
	for (i = 0; i < 8; ++i) {
		int nx = position.first + dx[i];
		int ny = position.second + dy[i];
		if (isInRange(nx, ny)) {
			tree.push(make_pair(1, make_pair(nx, ny)));
		}
	}
}

bool isInRange(int x, int y) {
	return (0 <= x && x < N && 0 <= y && y <= N);
}


// �ܿ￡�� S2D2�� ���� ���ƴٴϸ鼭 ���� ����� �߰��Ѵ�.
void winter() {
	//cout << "winter start" << endl;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			board[i][j] += A[i][j];
		}
	}
}

void printData() {
	/*
	cout << "===tree info===" << endl;
	for (auto tr : tree) {
		cout << "age : " << tr.first << " x : " << tr.second.first << " y : " << tr.second.second << endl;
	}
	*/
	cout << "============" << endl;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

}

void solution() {
	for (int i = 0; i < K; ++i) {
		//cout << "====" << i << "====" << endl;
		spring();
		summer();
		fall();
		winter();
		//cout << "after season, tree's size is " << tree.size() << endl;
		if (tree.size() == 0) return;
	}
}