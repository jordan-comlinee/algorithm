#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int W, N;
	// 가방 무게 W, 귀금속 종류 N
	int result = 0;
	scanf_s("%d %d", &W, &N);
	vector<vector<int>> jewerly(N, vector<int>(2));
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &jewerly[i][1], &jewerly[i][0]);
	}
	sort(jewerly.begin(), jewerly.end());
	while (W != 0) {
		int m = jewerly.back()[1];
		int p = jewerly.back()[0];
		if (W>m) {
			result += m * p;
			W -= m;
		}
		else {
			result += W * p;
			break;
		}
		jewerly.pop_back();
	}

	printf("%d", result);
	return 0;
	
}