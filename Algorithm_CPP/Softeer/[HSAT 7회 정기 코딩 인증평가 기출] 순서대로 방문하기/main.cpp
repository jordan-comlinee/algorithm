#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, cnt = 0;
vector<pair<int, int>> dest;
int board[5][5]{0};
bool visited[5][5]{false};
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isInScenario(int nx, int ny) {
	return (0 < nx && nx <= n && 0 < ny && ny <= n);
}

void dfs(pair<int, int> start, int idx) {
	// 인덱스가 m이면 마지막까지 다 도착했다는 뜻
	if (idx == m){
		cnt += 1;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = start.first + dx[i];
		int ny = start.second + dy[i];
		// 시나리오 내에 있고, 방문하지 않았으며, 장애물이 없는 경우
		if ( isInScenario(nx, ny) && !visited[nx][ny] && board[nx][ny] == 0) {
			// 방문 처리
			visited[nx][ny] = true;
			// 목적지에 도착하면 다음 목적지로 이동
			if (nx == dest[idx].first && ny == dest[idx].second) {
				dfs(dest[idx], idx + 1);
			}
			// 목적지에 도착하지 못하면 이동 위치로부터 다음 목적지로 이동
			else {
				dfs(make_pair(nx, ny), idx);
			}
			// 방문 끝, 되돌아가기
			visited[nx][ny] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < m; i++){
		cin >> x >> y;
		dest.push_back(make_pair(x, y));
	}
	// 출발지 방문 처리
	visited[dest[0].first][dest[0].second] = true;
	// 출발지 위치, 목적지 인덱스 매개변수
	dfs(dest[0], 1);
	cout << cnt << endl;
}