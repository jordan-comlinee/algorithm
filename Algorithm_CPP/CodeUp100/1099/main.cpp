#include<stdio.h>
using namespace std;

int main(void) {
	int maze[11][11];
	int x = 2, y = 2;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			scanf_s("%d", &maze[i][j]);
		}
	}
	while (true) {
		if (maze[x][y] == 2) {
			maze[x][y] = 9;
			break;
		}
		maze[x][y] = 9;
		// 오른쪽에 길이 없는 경우
		if (maze[x][y+1]==1) {
			if (maze[x+1][y]==1) {
				break;
			}
			else {
				++x;
			}
		}
		else {
			++y;
		}
	}
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	return 0;
}