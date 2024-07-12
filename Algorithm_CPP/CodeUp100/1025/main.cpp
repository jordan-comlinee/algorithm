#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int n[5];
	scanf_s("%1d%1d%1d%1d%1d", &n[0], &n[1], &n[2], &n[3], &n[4]);
	for (int i = 0; i < 5; i++) {
		printf("[%d]\n", int(n[i]*pow(10, 4-i)));
	}

	return 0;
}