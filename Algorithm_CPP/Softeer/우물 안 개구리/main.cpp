#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, M, a, b;
	int result = 0;
	scanf_s("%d %d", &N, &M);
	vector<int> w(N);
	vector<vector<int>> fri(N, vector<int>());
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &w[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &a, &b);
		fri[a-1].push_back(b-1);
		fri[b-1].push_back(a-1);
	}
	for (int i = 0; i < N; i++) {
		int isBest = 1;
		if (fri[i].size() >= 1) {
			for (int j = 0; j < fri[i].size(); j++) {
				if (w[i] <= w[fri[i][j]]) {
					isBest = 0;
				}
			}
		}
		result += isBest;
	}
	printf("%d", result);
	return 0;
}