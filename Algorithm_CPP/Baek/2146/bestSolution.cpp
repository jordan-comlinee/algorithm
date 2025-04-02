#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <memory.h>

using namespace std;

int minimum = 987654321;

int n;
int contury[100][100];

const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

inline int getMin(int x, int y) {
	if (x < y)
		return x;
	return y;
}

void bfs_island(int r, int c) {
	static int islandNum = 1;
	queue<pair<int, int>> q;
	q.emplace(r, c);
	contury[r][c] = ++islandNum;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nr < n && nc >= 0 && nc < n && contury[nr][nc] == 1) {
				contury[nr][nc] = islandNum;
				q.emplace(nr, nc);
			}
		}
	}
}

int bfs_bridge(int r, int c, int island) {
	queue<pair<int, int>> q;
	int depth = 1;
	int curElemNum = 1;
	q.emplace(r, c);
	bool visit[100][100];
	memset(visit, false, sizeof(bool) * 10000);
	visit[r][c] = true;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visit[nr][nc]) {
				if (contury[nr][nc] != island && contury[nr][nc] > 0) {
					return depth;
				}
				visit[nr][nc] = true;
				q.emplace(nr, nc);
			}
		}
		if (--curElemNum == 0) {
			if (++depth >= minimum)
				return 987654321;
			curElemNum = q.size();
		}
	}
	return 987654321;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &contury[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (contury[i][j] == 1) {
				bfs_island(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (contury[i][j] > 0)
				continue;
			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
					if (contury[nr][nc] > 0) {
						minimum = getMin(bfs_bridge(i, j, contury[nr][nc]), minimum);
						break;
					}
				}
			}
		}
	}
	printf("%d", minimum);
}