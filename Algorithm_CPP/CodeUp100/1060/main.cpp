#include <stdio.h>

int main(void) {
	long long int a, b;
	scanf_s("%lld %lld", &a, &b);
	printf("%lld", a&b);
	return 0;
}