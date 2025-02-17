#include<bits/stdc++.h>
using namespace std;
using dt = pair<int, pair<int, int>>;
const int MAX = 10;
// 땅의 크기, 나무의 개수, 시간
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
// 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
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
		//만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
		else {
			deadTree.push(make_pair(currentTreeSize, currentTreePos));
		}
	}
	// 살아 남은 나무들은 다시 tree 리스트에 넣는다.
	while (!nextTree.empty()) {
		tree.push(nextTree.top());
		nextTree.pop();
	}
	//cout << tree.size() << endl;

}
// 여름에는 봄에 죽은 나무가 양분으로 변하게 된다.
void summer() {
	//cout << "summer start" << endl;
	while (!deadTree.empty()) {
		// 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.
		int deadTreeSize = deadTree.top().first;
		pair<int, int> deadTreePos = deadTree.top().second;
		deadTree.pop();
		board[deadTreePos.first][deadTreePos.second] += deadTreeSize / 2;
	}
}
// 가을에는 나무가 번식한다.
void fall() {
	//cout << "fall start" << endl;
	while (!tree.empty()) {
		int currentTreeSize = tree.top().first;
		pair<int, int> currentTreePos = tree.top().second;
		tree.pop();
		//  번식하는 나무는 나이가 5의 배수이어야 하며,
		if (currentTreeSize % 5 == 0) {
			//cout << "reproduce" << endl;
			//인접한 8개의 칸에 나이가 1인 나무가 생긴다.
			reproduceTree(currentTreePos);
		}

		nextTree.push(make_pair(currentTreeSize, currentTreePos));

	}
	// 확인한 나무들은 다시 tree 리스트에 넣는다.
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


// 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다.
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