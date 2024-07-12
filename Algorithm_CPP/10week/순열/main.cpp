#include <iostream>
//#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[] = { 1, 2, 3 };
	vector<int> b = { 2, 1, 3, 100, 200 };
	sort(b.begin(), b.end());
	// 중복이 여러개 나올 예정. 왜 그러냐면 여러 가지 수의 순열에서 앞의 두개만 슬라이싱이 되므로...
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
	// 이런 방법도 가능함
	//  while (next_permutation(a, a+3));
	// 벡터의 경우
	// while (next_permutation(b.begin(), b.end()));
}