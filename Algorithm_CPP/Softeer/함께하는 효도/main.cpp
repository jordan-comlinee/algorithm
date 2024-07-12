#include <stdio.h>
const int MAX = 20;
using namespace std;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int n, m;
int field[MAX][MAX];
int check[MAX][MAX];
int result=0;
int m_list[3][2];

void dfs(int x, int y) {
	result += field[x][y];
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (0 < xx || xx >= n || 0 < yy || yy >= n) continue;
		result += 
	}
}

int main(void) {
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &field[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &m_list[i][0], &m_list[i][1]);
	}
	return 0;
}