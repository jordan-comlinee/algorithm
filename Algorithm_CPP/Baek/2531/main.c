#include<stdio.h>
#include <stdlib.h>
#define size_arr(x) sizeof(x)/sizeof(x[0])
#define MAX_D 3001

int slideWindow(int* sushi, int size, int k, int d, int c);

// 슬라이딩 원도우 활용하기 -> start & end 활용
int main(void) {
	(void)freopen("input.txt", "r", stdin);
	int N, d, k, c; // 접시 수, 초밥 가짓수, 연속해서 먹는 수, 쿠폰 초밥 번호
	int* sushi;	// 스시 동적 배열

	(void)scanf("%d %d %d %d", &N, &d, &k, &c);
	sushi = (int*)malloc((N+k-1) * sizeof(int));
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", sushi + i);
	}
	printf("%d", slideWindow(sushi, N, k, d, c));
	free(sushi);
	return 0;
}

int slideWindow(int* sushi, int N, int k, int d, int c) {
	int sushi_count[MAX_D] = { 0 };
	int current_sushis = 0;	// 현재 초밥 종류 수
	int max_result = 0; // 결과
	for (int i = 0; i < k; ++i) {
		if (sushi_count[sushi[i]] == 0) {
			current_sushis++;
		}
		sushi_count[sushi[i]]++;
	}
	
	max_result = current_sushis + (sushi_count[c] == 0 ? 1 : 0);
	for (int start = 0; start < N; ++start) {
		int end = (start + k)%N;
		if (--sushi_count[sushi[start]] == 0) {
			current_sushis--;
		}
		if (sushi_count[sushi[end]]++ == 0) {
			current_sushis++;
		}
		int result = current_sushis + (sushi_count[c] == 0 ? 1 : 0);
		max_result = max_result < result ? result : max_result;
	}
	return max_result;
}