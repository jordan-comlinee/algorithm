#include <stdio.h>
#include <iostream>
using namespace std;

// ���丮���� �ݺ��� ����� ������
int fact(int n) {
	if (n == 1 || n == 0) return 1;
	return n * fact(n - 1);
}
int fact1(int n) {
	int ret=1;
	for (int i = 1; i < n+1; i++) {
		ret *= i;
	}
	return ret;
}
// fibo �� DP�� ������� ������ for���� ����ϱ�� ����� 
int fibo(int n) {
	if (n == 0 || n == 1) return n;
	return fibo(n - 1) + fibo(n - 2);
}
int n = 5;

int main() {
	cout << fact(n) << " " << fact1(n) << " " << fibo(n) << endl;
}