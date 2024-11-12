#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int N = 0;
int result = 0;

int solution(int* buildings) {
	int cnt = 0;
	for (int i = 2; i < N-2; i++) {
		int near = max(max(buildings[i - 2], buildings[i - 1]),max(buildings[i + 1], buildings[i + 2]));
		if (near < buildings[i]){
			cnt += buildings[i] - near;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i < 11; i++) {
		cin >> N;
		int buildings[1001];
		for (int j = 0; j < N; j++) {
			cin >> buildings[j];
		}
		result = solution(buildings);
		cout << "#" << i << " " << result << endl;
	}
}