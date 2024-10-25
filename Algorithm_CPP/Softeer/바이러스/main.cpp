#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

const int MAX_VALUE = 1000000007;

int main(void) {
	long long int K, P, N;
	scanf("%lld %lld %lld", &K, &P, &N);
	long long int result = K % MAX_VALUE;
	for (int i = 0; i < N; i++) {
		result *= P%MAX_VALUE;
		result %= MAX_VALUE;
	}
	printf("%lld", result);
	return 0;
}