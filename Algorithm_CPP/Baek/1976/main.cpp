#include <bits/stdc++.h>
using namespace std;

int N, M; // 도시의 수, 여행 계획에 속한 도시들의 수
int a, b, c;
vector<vector<int>> connected;	// 도시 연결 정보
vector<int> destination; // 동혁이의 여행 계획
vector<int> cities;		// 도시들이 서로 연결되어있는지 확인
vector<int> parents;
bool isPossible = true;

void input_data();
void solution();
int find_parents(int target);
void union_parent(int a, int b);

int main() {
	input_data();
	solution();
	if (isPossible) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}



void input_data() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	connected.resize(N+1);
	cities.resize(N + 1);
	parents.resize(N + 1);
	for (int i = 1; i <= N; ++i){
		connected[i].resize(N + 1);
		for (int j = 1; j <= N; ++j) {
			cin >> a;
			connected[i][j] = a;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> a;
		destination.push_back(a);
	}
}

void solution() {
	for (int i = 1; i <= N; ++i) {
		parents[i] = i;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
		{
			if (connected[i][j] == 1) {
				//cout << i << "and " << j << " isconnected" << endl;
				union_parent(i, j);
			}
		}
	}
	/*
	for (int i = 1; i <= N; i++) {
		cout << find_parents(i) <<" ";
	}
	*/
	//cout << endl;
	for (int i = 0; i < M-1; ++i) {
		if (find_parents(destination[i]) != find_parents(destination[i+1])) {
			isPossible = false;
			return;
		}
	}
}

int find_parents(int target) {
	if (target == parents[target]) return target;
	return parents[target] = find_parents(parents[target]);
}

void union_parent(int a, int b) {
	a = find_parents(a);
	b = find_parents(b);
	parents[b] = a;
}