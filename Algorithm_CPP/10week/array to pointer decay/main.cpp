#include <bits/stdc++.h>
using namespace std;
// 배열의 이름은 주소값으로 쓸 수 있음 (array to pointer decay)
// vector<int> a 와 같은 동적은 안되고 int[] | string[]이런 정적 배열만 가능함
int a[4];
int main() {
	int* c = a;
	cout << c << '\n' << &a << endl;
	cout << ++c << '\n' << &(a[1]) << endl;
	cout << c+1 << '\n' << &(a[2]) << endl;
}