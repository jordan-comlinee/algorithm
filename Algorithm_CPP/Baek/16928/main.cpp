#include<bits/stdc++.h>
using namespace std;

int N, M, maps = 0;
int a, b;
map<int, int> ladder, snake;
int board[101] = { 0 };
#define LADDER 1
#define SNAKE 2

void bfs() {
	queue<int> visit;
	int visited[101] = { 0 };
	visit.push(1);
	while (!visit.empty()) {
		int current = visit.front();
		visit.pop();

		if (current == 100){
			maps = visited[current];
			return;
		}

		for (int i = 1; i <= 6; i++) {
			int next = current + i;
			if (next > 100) continue;

			int arrive = current + i;
			if (board[next] == LADDER) {
				arrive = ladder[next];
			}
			else if (board[next] == SNAKE) {
				arrive = snake[next];
			}
			if (visited[arrive] == 0) {
				visited[arrive] = visited[current] + 1;
				visit.push(arrive);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		ladder[a] = b;
		board[a] = LADDER;
	}
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		snake[a] = b;
		board[a] = SNAKE;
	}
	bfs();
	cout << maps << endl;
}