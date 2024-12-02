#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<int> bridge(N, 0);
	vector<int> cnt(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> bridge[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (bridge[j] < bridge[i]) {
				cnt[i] = max(cnt[i], cnt[j] + 1);
			}
		}
	}
	cout << *max_element(cnt.begin(), cnt.end())+1 << endl;

}