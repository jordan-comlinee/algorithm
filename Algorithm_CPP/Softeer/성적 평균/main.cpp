#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
	int N, K, a, b;
	scanf_s("%d %d", &N, &K);
	vector<int> score_list(N);
	vector<double> avg_list(K);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &score_list[i]);
	}
	for (int i = 0; i < K; i++) {
		scanf_s("%d %d", &a, &b);
		int sum = 0;
		for (int j = a-1; j < b; j++) {
			sum += score_list[j];
		}
		avg_list[i] = double(sum)/double((b-a+1));
	}
	for (int i = 0; i < K; i++) {
		printf("%.2f\n", avg_list[i]);
	}
}