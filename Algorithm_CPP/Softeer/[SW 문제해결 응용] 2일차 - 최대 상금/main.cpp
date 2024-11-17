#include<bits/stdc++.h>
using namespace std;

string num;
int swapCnt, result;

void dfs(int cnt, int idx) {
	if (cnt == swapCnt) {
		result = max(result, stoi(num));
		return;
	}
	for (int i = idx; i < num.length() - 1; i++) {
		for (int j = i + 1; j < num.length(); j++) {
			if (num[i] <= num[j]) {
				swap(num[i], num[j]);
				dfs(cnt + 1, i);
				swap(num[i], num[j]);
			}
			if (i == num.length() - 2 && j == num.length() - 1) {
				swap(num[i], num[j]);
				dfs(cnt + 1, i);
				swap(num[i], num[j]);
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> num >> swapCnt;
		result = 0;
		dfs(0, 0);
		cout << "#" << t << " " << result << endl;
	}
}