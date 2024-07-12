#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	int N;
	scanf_s("%d", &N);
	vector<int> n(N+1);
	n[0] = 2;
	for (int i = 1; i < N+1; i++) {
		n[i] = n[i - 1] + pow(2, i-1);
	}
	printf("%d", n[N]*n[N]);

}