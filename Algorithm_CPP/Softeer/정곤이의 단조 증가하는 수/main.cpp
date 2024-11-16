#include <bits/stdc++.h>
using namespace std;

int T, N;
int numbers[1000] = { 0 };


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++){
		int result = -1;
		cin >> N;
		for (int n = 0; n < N; n++) {
			cin >> numbers[n];
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				bool isIncreasing = true;
				int current = numbers[i] * numbers[j];
				if (result < current) {
					int num = current;
					while (num) {
						if (num % 10 < (num / 10) % 10) {
							isIncreasing = false;
							break;
						}
						num /= 10;
					}
					if (isIncreasing) {
						result = current;
					}
				}
			}
		}
		cout << "#" << t << " " << result << endl;
		memset(numbers, 0, sizeof(numbers));
	}
}