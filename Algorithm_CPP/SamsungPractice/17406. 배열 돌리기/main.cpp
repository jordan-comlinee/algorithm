#include <bits/stdc++.h>
using namespace std;

struct SpinInfo {
	int r;
	int c;
	int s;
	SpinInfo(int r, int c, int s) : r(r), c(c), s(s) {};
};

const int MAX = 50;
int N, M, K;
int board[MAX][MAX];
vector<SpinInfo> spins;

void inputData();
void solution();
void spin(SpinInfo si);

int main() {
	inputData();
	solution();
}

void inputData() {
	cin >> N >> M >> K;
	for (int n = 0; n < N; ++n) {
		for (int m = 0; m < M; ++m) {
			cin >> board[n][m];
		}
	}
	for (int k = 0; k < K; ++k) {
		int k1, k2, k3;
		cin >> k1 >> k2 >> k3;
		spins.push_back(SpinInfo(k1, k2, k3));
	}
}

void spin(SpinInfo si) {

}

void solution() {
	for (int k = 0; k < K; ++k) {
		spin(spins[k]);
	}
}