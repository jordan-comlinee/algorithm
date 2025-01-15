#include <stdio.h>
#define MAX 100

static int t = 0;					// t = 색종이 개수, result = 면적(답)
static int dohwaji[MAX + 1][MAX + 1] = { 0 };	// 도화지
static int paper_x[MAX], paper_y[MAX];

void input_data(void);
int solution(void);

int main() {
	input_data();
	printf("%d\n", solution());
	return 0;
}

void input_data(void) {
	(void)scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		(void)scanf("%d %d", &paper_x[i], &paper_y[i]);
	}
	return;
}
int solution(void) {
	int result = 0;
	// t의 max = 100, x = 10, y = 10, 최대 연산 = 100*10*10 = 10000회
	for (int i = 0; i < t; i++) {
		int X = paper_x[i];					// 각 색종이의 x 좌표
		int Y = paper_y[i];					// 각 색종이의 y 좌표
		for (int x = 0; x < 10; ++x) {
			for (int y = 0; y < 10; ++y) {
				if (!dohwaji[X + x][Y + y]) {
					dohwaji[X + x][Y + y] = 1;
					++result;
				}
			}
		}
	}
	return result;
}
