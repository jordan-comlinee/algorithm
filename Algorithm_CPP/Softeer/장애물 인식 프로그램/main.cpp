#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 25;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int N;
int cnt;
int check[MAX][MAX];
int map[MAX][MAX];
vector<int> blocks;

void dfs(int x, int y) {
	check[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= N || yy < 0 || yy >= N || map[xx][yy] == 0) continue;
		if (check[xx][yy] == 0) {
			check[xx][yy] = 1;
			dfs(xx, yy);
		}
	}
}

int main(void) {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] != 0 || map[i][j] == 0) continue;
			cnt = 0;
			dfs(i, j);
			blocks.push_back(cnt);
		}
	}


	sort(blocks.begin(), blocks.end());
	printf("%d\n", blocks.size());
	for (int i = 0; i < blocks.size(); i++){
		printf("%d\n", blocks[i]);
	}

	return 0;

}