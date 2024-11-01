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
	// �ε����� m�̸� ���������� �� �����ߴٴ� ��
	if (idx == m){
		cnt += 1;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = start.first + dx[i];
		int ny = start.second + dy[i];
		// �ó����� ���� �ְ�, �湮���� �ʾ�����, ��ֹ��� ���� ���
		if ( isInScenario(nx, ny) && !visited[nx][ny] && board[nx][ny] == 0) {
			// �湮 ó��
			visited[nx][ny] = true;
			// �������� �����ϸ� ���� �������� �̵�
			if (nx == dest[idx].first && ny == dest[idx].second) {
				dfs(dest[idx], idx + 1);
			}
			// �������� �������� ���ϸ� �̵� ��ġ�κ��� ���� �������� �̵�
			else {
				dfs(make_pair(nx, ny), idx);
			}
			// �湮 ��, �ǵ��ư���
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
	// ����� �湮 ó��
	visited[dest[0].first][dest[0].second] = true;
	// ����� ��ġ, ������ �ε��� �Ű�����
	dfs(dest[0], 1);
	cout << cnt << endl;
}