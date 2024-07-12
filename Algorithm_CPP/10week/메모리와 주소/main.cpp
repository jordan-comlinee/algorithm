#include <bits/stdc++.h>
using namespace std;

int i;

int main() {
	// &는 메모리 주소를 가져오는 것!!
	// 메모리 주소는 OS 실행 시간 등등에 따라 달라진다.
	cout << &i << endl;
	// i에 값을 할당해도 주소는 바뀌지 않음!
	i = 0;
	cout << &i << endl;

}