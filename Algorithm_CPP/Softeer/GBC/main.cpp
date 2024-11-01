#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int isOverSpeed(int a, int b, int result) {
	if (a > b) {
		if (result>a-b){
			return result;
		}
		return a - b;
	} else{
		return result;
	}
}

int main() {
	int N, M, result = 0;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	vector<pair<int, int>> elv(N);
	for (int i = N-1; i >= 0; i--) {
		cin >> elv[i].first >> elv[i].second;
	}
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		while (x>0) {
			int cur = elv[elv.size() - 1].first;
			int speed = elv[elv.size() - 1].second;
			if (x >= cur) {
				x = x - cur;
				result = isOverSpeed(y, speed, result);
				elv.pop_back();
			} else {
				elv[elv.size() - 1].first = cur - x;
				result = isOverSpeed(y, speed, result);
				x = 0;
			}
		}
	}
	cout << result << endl;
}