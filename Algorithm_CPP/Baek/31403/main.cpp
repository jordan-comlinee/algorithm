#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A, B, C;
	cin >> A >> B >> C;
	cout << A + B -C << endl;
	cout << stoi(to_string(A) + to_string(B))-C << endl;
}