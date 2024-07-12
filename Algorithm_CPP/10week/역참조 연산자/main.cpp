#include <bits/stdc++.h>
using namespace std;
int main() {
	string a = "soyoung";
	string* b = &a;
	// 역참조 연산자를 통해 주소에 어떤 값이 있는 지 가져오는 것임
	cout << b << '\n' << *b << endl;
}