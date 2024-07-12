#include <bits/stdc++.h>
using namespace std;
// 재귀함수를 이용해서 조합을 구현하는 법

// n개 중에서 k개를 뽑는 것임!
int n = 5, k = 3;
int a[5] = {1, 2, 3, 4, 5};

void print(vector<int> b) {
	for (int i : b) cout << i << " ";
	cout << "\n";
}
void combi(int start, vector<int> b) {
	// 조합에서 다 뽑아낸 경우!
	if (b.size() == k) {
		// 뽑은 것을 모두 출력함! **얘는 인덱스를 출력하는 것임**
		print(b);
		return;
	}
	//
	for (int i = start + 1; i < n; i++) {
		// 트리 위로 올라감!
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

	// 중첩 for문을 이용하는 방법
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				cout << i << " : " << j << " : " << k << endl;
			}
		}
	}
	cout << "=====================" << endl;
	// 중첩 for문을 이용하는 방법2
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				cout << i << " : " << j << " : " << k << endl;
			}
		}
	}
}