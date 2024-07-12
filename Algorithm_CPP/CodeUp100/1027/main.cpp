#include <stdio.h>
using namespace std;

int main(void) {
	int y, m, d;
	scanf_s("%4d.%2d.%2d", &y, &m, &d);
	printf("%02d-%02d-%04d", d, m, y);
}