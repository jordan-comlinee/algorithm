#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int check(string str) {
	int cnt=0;
	for (int i = 1; i < str.size()+1; i++) {
		string a = str.substr(0, i);
		if ( a == str.substr(i, i)) {
			return a.size();
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int result = 0;
		string input_str;
		cin >> input_str;
		result = check(input_str);
		cout << "#" << i << " " << result << endl;
	}
}