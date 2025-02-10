#include<bits/stdc++.h>
using namespace std;

int N, S;
vector<int> N_arr;
int result = 0;

void input_data() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> S;
	N_arr.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> N_arr[i];
	}
}

void print_data() {
	cout << N << " " << S << endl;
	for (auto i : N_arr) {
		cout << i << " ";
	}
	cout << endl;
}

void solution(int idx, int sum, bool included) {
	if (idx == N) {
		if (included && sum == S) {
			result += 1;
		}
		return;
	}
	solution(idx + 1, sum, included);
	solution(idx + 1, sum + N_arr[idx], true);
}

int main(void) {
	input_data();
	solution(0, 0, false);
	cout << result << endl;
	return 0;
}