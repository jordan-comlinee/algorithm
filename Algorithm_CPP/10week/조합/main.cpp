#include <bits/stdc++.h>
using namespace std;
// ����Լ��� �̿��ؼ� ������ �����ϴ� ��

// n�� �߿��� k���� �̴� ����!
int n = 5, k = 3;
int a[5] = {1, 2, 3, 4, 5};

void print(vector<int> b) {
	for (int i : b) cout << i << " ";
	cout << "\n";
}
void combi(int start, vector<int> b) {
	// ���տ��� �� �̾Ƴ� ���!
	if (b.size() == k) {
		// ���� ���� ��� �����! **��� �ε����� ����ϴ� ����**
		print(b);
		return;
	}
	//
	for (int i = start + 1; i < n; i++) {
		// Ʈ�� ���� �ö�!
		b.push_back(i);
		combi(i, b);
		// 
		b.pop_back();
	}
	return;
}

int main() {
	vector<int> b;
	combi(-1, b);

	// ��ø for���� �̿��ϴ� ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				cout << i << " : " << j << " : " << k << endl;
			}
		}
	}
	cout << "=====================" << endl;
	// ��ø for���� �̿��ϴ� ���2
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				cout << i << " : " << j << " : " << k << endl;
			}
		}
	}
}