#include <bits/stdc++.h>
using namespace std;
int main() {
	string a = "soyoung";
	string* b = &a;
	// ������ �����ڸ� ���� �ּҿ� � ���� �ִ� �� �������� ����
	cout << b << '\n' << *b << endl;
}