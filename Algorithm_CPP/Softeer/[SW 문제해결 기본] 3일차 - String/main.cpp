#include <bits/stdc++.h>
using namespace std;

int search(string target, string sentence) {
	int cnt = 0;
	for (int i = 0; i < sentence.size()-target.size()+1; i++) {
		if (sentence.substr(i, target.size()) == target) { cnt++; }
	}
	return cnt;
};

int main() {
	for (int t = 1; t <= 10; t++) {
		int T, result;
		string target, sentence;
		cin >> T;
		cin >> target >> sentence;
		result = search(target, sentence);
		cout << "#" << t << " " << result << endl;
	}
}