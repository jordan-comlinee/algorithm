#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> q;

void solution(string command) {
	int data;
	if (command == "push") {
		cin >> data;
		q.push(data);
	}
	else if (command == "pop") {
		if (!q.empty()) {
			cout << q.front() << endl;
			q.pop();
		}
		else {
			cout << -1 << endl;
		}
	}
	else if (command == "size") {
		cout << q.size() << endl;
	}
	else if (command == "empty") {
		if (q.empty()) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	else if (command == "front") {
		if (!q.empty()) {
			cout << q.front() << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	else if (command == "back") {
		if (!q.empty()) {
			cout << q.back() << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}
void input_data() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string command;
		cin >> command;
		solution(command);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input_data();
}