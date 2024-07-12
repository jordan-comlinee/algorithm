#include <stdio.h>

int main(void) {
	long long int K, P, N;
	scanf_s("%lld %lld %lld", &K, &P, &N);
	long long int result = K % 1000000007;
	for (int i = 0; i < N; i++) {
		result *= P%1000000007;
	}
	printf("%lld", result);
	return 0;
}