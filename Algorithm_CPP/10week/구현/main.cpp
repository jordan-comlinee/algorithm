#include<bits/stdc++.h>

using namespace std;

string dopa = "abcde";

//Q1. �տ������� 3���� ���ڿ��� ����϶�.
//Q2. �ش� ���ڿ��� �Ųٷ� �ؼ� ����϶�.
//Q3. �ش� ���ڿ� ���� "umzunsik"�̶� ���ڿ��� �߰��϶�.
int main() {
	// 3�� ���
	cout << dopa.substr(0, 3) << "\n";
	// �Ųٷ� ���
	reverse(dopa.begin(), dopa.end());
	// ���ؽ� �߰� ���
	cout << dopa + " umzunsik" << "\n";
	return 0;
}