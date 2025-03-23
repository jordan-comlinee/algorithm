#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
int N;
vector<int> A;
vector<int> B;
int result=0;

void inputData();
void solution();

int main() {
	inputData();
	solution();
	cout << result << endl;
}

void inputData() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
}

void solution() {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());
	for (int i = 0; i < N; ++i) {
		result += A[i] * B[i];
	}
	return;
}