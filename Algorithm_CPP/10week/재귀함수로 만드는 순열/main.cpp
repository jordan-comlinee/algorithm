#include <bits/stdc++.h>
using namespace std;
int v[3] = { 1, 2, 3 };
int n = 3, r = 3;

void print() {
	for (int i = 0; i < r; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

// n�� �� r���� ���� ��!
void makePermutation(int n, int r, int depth) {
	// ���࿡ depth�� r���� �̴� �Ͱ� ���ٸ�?
	if (r == depth) {
		print();
		return;
	}
	for (int i = depth; i < n; i++) {
		// �������� ������ ���� tree�� ���� �ö�
		cout << i << " : " << depth << "�� �ٲ۴�!\n";
		swap(v[i], v[depth]);
		// makePermutation ���� -> n, r, depth+1 �� root�� �ϴ� ����� �� ã��
		makePermutation(n, r, depth + 1);
		// ������ �ϴ� ��
		cout << i << " : " << depth << "�� �ǵ�����!\n";
		swap(v[i], v[depth]);
	}
	return;
}

int main(void) {
	makePermutation(n, r, 0);
}