#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int T = 0;
int N, M, K;

pair<int, int> get_direction(int d) {
	if (d == 1) { return make_pair(0, -1); }
	else if (d == 2) { return make_pair(0, 1); }
	else if (d == 3) { return make_pair(-1, 0); }
	else if (d == 4) {	return make_pair(1, 0); }
	else { return make_pair(0, 0); }
}

struct germs {
	pair<int, int> location;
	int count;
	pair<int, int> direction;
	germs(int a, int b, int c, int d)
		: location(make_pair(a, b)), count(c), direction(get_direction(d)) {}
};

void solution(int n, int m, int k) {
	vector<germs> colonies;
	for (int i = 0; i < K; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		colonies.push_back(germs(a, b, c, d));
	}
	for (int i = 0; i < M; i++){
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> M >> K;
		solution(N, M, K);
	}
}