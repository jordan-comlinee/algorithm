#include <bits/stdc++.h>
using namespace std;
#define MAX 25

int N;
vector<string> maps;
vector<int> maps;
bool visited[MAX + 1][MAX + 1] = { false };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int dfs(int x, int y);
void solution();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	maps = vector<string>(N);
	for (int i = 0; i < N; i++) {
		cin >> maps[i];
	}
	solution();
	return 0;
}

void solution() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (maps[i][j] == '1' && !visited[i][j]) {
				count = dfs(i, j);
				maps.push_back(count);
			}
		}
	}
	sort(maps.begin(), maps.end());
	cout << maps.size() << endl;
	for (int i : maps) {
		cout << i << endl;
	}
}

int dfs(int x, int y) {
	visited[x][y] = true;
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny] && maps[nx][ny] == '1') {
			//cout << nx << " " << ny << endl;
			cnt += dfs(nx, ny);
		}
	}
	return cnt;
}