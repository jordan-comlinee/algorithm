#include <bits/stdc++.h>
using namespace std;

int T, M, N, x, y, result = -1;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * (b / gcd(a, b));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++) {
		result = -1;
		cin >> M >> N >> x >> y;
		int LCM = lcm(M, N);
		for (int i = x; i <= LCM; i+=M) {
			int ny = (i % N == 0) ? N : (i % N);
			if (ny == y) {
				result = i;
				break;
			}
		}
		cout << result << endl;
	}
	
}