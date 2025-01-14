#include<stdio.h>
#include <stdlib.h>
#define size_arr(x) sizeof(x)/sizeof(x[0])
#define MAX_D 3001

int slideWindow(int* sushi, int size, int k, int d, int c);

// �����̵� ������ Ȱ���ϱ� -> start & end Ȱ��
int main(void) {
	(void)freopen("input.txt", "r", stdin);
	int N, d, k, c; // ���� ��, �ʹ� ������, �����ؼ� �Դ� ��, ���� �ʹ� ��ȣ
	int* sushi;	// ���� ���� �迭

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
	int current_sushis = 0;	// ���� �ʹ� ���� ��
	int max_result = 0; // ���
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