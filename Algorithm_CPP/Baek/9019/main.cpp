#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

int T, A, B;
bool visited[MAX + 1] = {false};
string commands[MAX + 1];

int D(int n) {
	return (n * 2) % MAX;
}

int S(int n) {
	return (n == 0) ? 9999 : n - 1;
}

int L(int n) {
	int d1 = n / 1000;
	int rest = n % 1000;
	return (rest * 10) + d1;
}

int R(int n) {
	int d4 = n % 10;
	return (d4 * 1000) + (n / 10);
}
void bfs() {
	queue<int> aqueue;
	aqueue.push(A);
	visited[A] = true;
	commands[A] = "";
	while (!aqueue.empty()) {
		int current = aqueue.front();
		aqueue.pop();
		if (current == B) return;
		vector<pair<int, char>> operations = {
			{D(current), 'D'},
			{S(current), 'S'},
			{L(current), 'L'},
			{R(current), 'R'}
		};

		for (int i = 0; i < 4; i++) {
			if (!visited[operations[i].first]) {
				visited[operations[i].first] = true;
				commands[operations[i].first] = commands[current] + operations[i].second;
				aqueue.push(operations[i].first);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> A >> B;
		bfs();
		cout << commands[B] << endl;
		fill(visited, visited + MAX + 1, false);
		fill(commands, commands + MAX + 1, "");
	}
	
}