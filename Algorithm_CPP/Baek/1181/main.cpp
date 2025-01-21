#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	set<string> set_words;
	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq_words;
	for (int i = 0; i < N; i++){
		string word;
		cin >> word;
		if (set_words.find(word) == set_words.end()) {
			set_words.insert(word);
			pq_words.push({ word.size(), word });
		}
	}
	while (!pq_words.empty()) {
		cout << pq_words.top().second << endl;
		pq_words.pop();
	}
	return 0;

}