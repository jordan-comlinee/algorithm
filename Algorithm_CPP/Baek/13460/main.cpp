#include<bits/stdc++.h>
#include<deque>
using namespace std;
#define MAX 11
int N, M;
pair<int, int> Red = make_pair(0, 0), Blue = make_pair(0, 0);
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
deque<vector<int>> q;
char board[11][11] = { "" };
bool visited[11][11][11][11] = {false};

pair<pair<int, int>, int> move(int x, int y, int dx, int dy) {
	// 이동한 칸 수
	int cnt = 0;
	while (board[x+dx][y+dy] != '#' && board[x][y] != 'O'){
		x += dx;
		y += dy;
		cnt += 1;
	}
	return make_pair(make_pair(x, y), cnt);
}

int bfs() {
	q.push_back({ Red.first, Red.second, Blue.first, Blue.second, 1 });
	while (!q.empty()) {
		int rx = q.front()[0];
		int ry = q.front()[1];
		int bx = q.front()[2];
		int by = q.front()[3];
		int cnt = q.front()[4];
		q.pop_front();
		if (cnt > 10) {
			return -1;
		}
		for (int i = 0; i < 4; i++) {
			// 각 돌의 x y 좌표, 카운트 
			pair<pair<int, int>, int> nRed = move(rx, ry, dx[i], dy[i]);
			pair<pair<int, int>, int> nBlue = move(bx, by, dx[i], dy[i]);
			int nrx = nRed.first.first, nry = nRed.first.second, nrc = nRed.second;
			int nbx = nBlue.first.first, nby = nBlue.first.second, nbc = nBlue.second;
			if (board[nbx][nby] != 'O') {
				if (board[nrx][nry] == 'O') {
					return cnt;
				}
				if (nrx == nbx && nry == nby){
					if (nrc > nbc) {
						nrx -= dx[i];
						nry -= dy[i];
					}
					else {
						nbx -= dx[i];
						nby -= dy[i];
					}
				}
				if (!visited[nrx][nry][nbx][nby]) {
					visited[nrx][nry][nbx][nby] = true;
					q.push_back({ nrx, nry, nbx, nby, cnt + 1 });
				}
			}
		}
	}
	return -1;
}

void solution() {
	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> board[n][m];
			if (board[n][m] == 'R') {
				Red.first = n;
				Red.second = m;
			}
			else if (board[n][m] == 'B') {
				Blue.first = n;
				Blue.second = m;
			}
		}
	}
	cout << bfs() << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

}