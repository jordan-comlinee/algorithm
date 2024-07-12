#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int N, M, K;
	int result = 2147483647;
	scanf_s("%d %d %d", &N, &M, &K);
	vector<int> n(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &n[i]);
	}
	sort(n.begin(), n.end());
	do {
		int sum = 0, temp = 0, idx = 0;
		for (int i = 0; i < K; i++) {
			temp = 0;
			while (temp + n[idx] <= M) {
				temp += n[idx];
				sum += n[idx];
				idx = (idx + 1) % N;
			}
		}
		result = min(result, sum);
	} while (next_permutation(n.begin(), n.end()));
	printf("%d", result);
	return 0;
}