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

// n개 중 r개를 뽑을 때!
void makePermutation(int n, int r, int depth) {
	// 만약에 depth가 r개를 뽑는 것과 같다면?
	if (r == depth) {
		print();
		return;
	}
	for (int i = depth; i < n; i++) {
		// 여러가지 조합을 위해 tree의 위로 올라감
		cout << i << " : " << depth << "를 바꾼다!\n";
		swap(v[i], v[depth]);
		// makePermutation 수행 -> n, r, depth+1 을 root로 하는 경우의 수 찾기
		makePermutation(n, r, depth + 1);
		// 복원을 하는 것
		cout << i << " : " << depth << "를 되돌린다!\n";
		swap(v[i], v[depth]);
	}
	return;
}

int main(void) {
	makePermutation(n, r, 0);
}