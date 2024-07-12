#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(void) {
	int h, w, n, l, d, x, y;
	// �������� ����  �� ���� �Է�
	scanf_s("%d %d", &h, &w);
	vector<vector<int>> board(h, vector<int>(w, 0));


	// ���� �� �ִ� ������ ����
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d %d %d", &l, &d, &x, &y);
		--x; --y;
		if (!d) {
			for (int i = 0; i < l; i++) {
				board[x][y + i] = 1;
			}
		}
		else {
			for (int i = 0; i < l; i++) {
				board[x + i][y] = 1;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}

	return 0;
}
