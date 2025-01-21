#include <bits/stdc++.h>
using namespace std;

int N;
int result = 0;
priority_queue<int, vector<int>, greater<int>> cards;

void input_data(void) {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int card;
		cin >> card;
		cards.push(card);
	}
	return;
}

void solution() {
	while (cards.size() > 1) {
		int a = cards.top();
		cards.pop();
		int b = cards.top();
		cards.pop();
		int hap = a + b;
		result += hap;
		cards.push(hap);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input_data();
	solution();
	cout << result << endl;
	return 0;
}