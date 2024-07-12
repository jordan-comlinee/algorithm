#include <stdio.h>

int main(void) {
	int n, x, y;
	int board[19][19] = {};
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			scanf_s("%d", &board[i][j]);
		}
	}

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &x, &y);

		for (int j = 0;j < 19; j++) {
			board[x - 1][j] = !board[x - 1][j];
		}
		for (int j = 0; j < 19; j++) {
			board[j][y - 1] = !board[j][y - 1];
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			printf("%d ", board[i][j]);
		}
		if (i == 18){
			return 0;
		}
		printf("\n");
	}
	return 0;

}