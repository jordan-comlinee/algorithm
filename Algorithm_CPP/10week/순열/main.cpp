#include <iostream>
//#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[] = { 1, 2, 3 };
	vector<int> b = { 2, 1, 3, 100, 200 };
	sort(b.begin(), b.end());
	// �ߺ��� ������ ���� ����. �� �׷��ĸ� ���� ���� ���� �������� ���� �ΰ��� �����̽��� �ǹǷ�...
	do {
		for (int i = 0; i < 2; i++) {
			cout << b[i] << " ";
		}
		cout << '\n';
	} while (next_permutation(b.begin(), b.end()));

	cout << "==================================" << endl;
	do {
		/*
		for (int i : a) cout << i << " ";
		cout << "\n";
		*/

	} while (next_permutation(&a[0], &a[0] + 3));
	// �̷� ����� ������
	//  while (next_permutation(a, a+3));
	// ������ ���
	// while (next_permutation(b.begin(), b.end()));
}