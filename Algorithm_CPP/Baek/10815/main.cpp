#include <bits/stdc++.h>
using namespace std;

int N, M, a;
int hasCard[20000000] = {0};
string maps;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<int> sanggeun(N);
	for (int n = 0; n < N; n++){
		cin >> a;
		hasCard[a+10000000] = 1;
	}
	cin >> M;
	for (int m = 0; m < M; m++){
		cin >> a;
		maps += to_string(hasCard[a + 10000000]) + " ";
	}
	cout << maps << endl;

}