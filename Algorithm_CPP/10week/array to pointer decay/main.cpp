#include <bits/stdc++.h>
using namespace std;
// �迭�� �̸��� �ּҰ����� �� �� ���� (array to pointer decay)
// vector<int> a �� ���� ������ �ȵǰ� int[] | string[]�̷� ���� �迭�� ������
int a[4];
int main() {
	int* c = a;
	cout << c << '\n' << &a << endl;
	cout << ++c << '\n' << &(a[1]) << endl;
	cout << c+1 << '\n' << &(a[2]) << endl;
}