#include<bits/stdc++.h>
using namespace std;

int N, T, P;
const int MAX = 16;
vector<pair<int, int>> time_table(MAX);
int result = 0;

void input_data();
void solution();

int main() {
	input_data();
	solution();
	cout << result << endl;
}

void input_data() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> T >> P;
		time_table[i] = make_pair(T, P);
	}
}

void solution() {
	int last_idx = N;
	for (int i = N-1; i >= 0; --i) {
		if (i+time_table[i].first-1 < last_idx){
			cout << "selected : " << i << " last index : "<< last_idx << endl;
			result += time_table[i].second;
			last_idx = i;
		}
	}
}