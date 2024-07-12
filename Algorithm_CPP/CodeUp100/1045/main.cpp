#include<stdio.h>
using namespace std;

int main(void) {
	long long int a, b;
	scanf_s("%lld %lld", &a, &b);
	printf("%lld\n%lld\n%lld\n%lld\n%d\n%.2f", a+b, a-b, a*b, a/b, a%b, float(a)/float(b));
	return 0;
}