#include<bits/stdc++.h>
using namespace std;
using dt = pair<int, pair<int, int>>;
const int MAX = 11;
// 땅의 크기, 나무의 개수, 시간
int N, M, K;
int board[MAX][MAX] = { 0 };
vector<int> treeBoard[MAX][MAX];
int A[MAX][MAX] = { 0 };
int dx[] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dy[] = { -1, 1, 0, -1, 1, 0, -1, 1 };

void inputData();
void springSummer();
void growTree(int x, int y);
void fall();
void reproduceTree(int x,  int y);
bool isInRange(int x, int y);
void winter();
void printData();
void solution();

int main() {
	inputData();
	solution();
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			//cout << treeBoard[i][j].size() << " ";
			//for (auto tr : treeBoard[i][j]) {
			//	cout << "board[" << i << "][" << j << "] = " << tr << endl;
			//}
			cnt += treeBoard[i][j].size();
		}
		//cout << endl;
	}
	cout << cnt << endl;
}


void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fill(&board[0][0], &board[MAX-1][MAX-1], 5);
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		treeBoard[x - 1][y - 1].push_back(z);
	}
}
// 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
void springSummer() {
	//cout << "spring & summer start" << endl;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!treeBoard[i][j].empty()) {
				//cout << "is not empty" << endl;
				growTree(i, j);
			}
		}
	}

}

void growTree(int x, int y) {
	//cout << "grow start" << endl;
	queue<int> deadTree;
	sort(treeBoard[x][y].begin(), treeBoard[x][y].end());
	int score = 0;
	for (int i = 0; i < treeBoard[x][y].size(); ++i) {
		if (treeBoard[x][y][i] > 0) {
			if (board[x][y] >= treeBoard[x][y][i]) {
				board[x][y] -= treeBoard[x][y][i];
				treeBoard[x][y][i] += 1;
			}
			else {
				score += treeBoard[x][y][i] / 2;
				treeBoard[x][y][i] = -1;
				
			}
		}
		
	}
	treeBoard[x][y].erase(remove(treeBoard[x][y].begin(), treeBoard[x][y].end(), -1), treeBoard[x][y].end());
	// summer
	board[x][y] += score;

}
// 가을에는 나무가 번식한다.
void fall() {
	//  번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
	//cout << "fall start" << endl;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			//cout << "x : " << i << " y : " << j << "tree size : " << treeBoard[i][j].size() << endl;
			for (auto tree : treeBoard[i][j]) {
				//cout << tree << endl;
				if (tree % 5 == 0) {
					//cout << "grow" << endl;
					reproduceTree(i, j);
				}
			}
		}
	}
	//cout << tree.size() << endl;
}

void reproduceTree(int x, int y) {
	for (int i = 0; i < 8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isInRange(nx, ny)) {
			treeBoard[nx][ny].push_back(1);
		}
	}
}

bool isInRange(int x, int y) {
	return (0 <= x && x < N && 0 <= y && y < N);
}


// 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다.
void winter() {
	//cout << "winter start" << endl;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
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
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

}

void solution() {
	for (int i = 0; i < K; ++i) {
		//cout << "====" << i << "====" << endl;
		springSummer();
		fall();
		winter();
		//cout << "after season, tree's size is " << tree.size() << endl;
		if (M == 0) return;

		//for (int i = 0; i < N; ++i) {
		//	for (int j = 0; j < N; ++j) {
		//		//cout << treeBoard[i][j].size() << " ";
		//		for (auto tr : treeBoard[i][j]) {
		//			cout << "board[" << i << "][" << j << "] = " << tr << endl;
		//		}
		//	}
		//	//cout << endl;
		//}
		//cout << "=============" << endl;
	}
}