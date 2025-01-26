// 지민이가 거짓말쟁이로 알려지지 않으면서, 과장된 이야기를 할 수 있는 파티 개수의 최댓값을 구하는 프로그램
// 지민이는 모든 파티에 참가해야 한다.
// 사람들의 번호는 1부터 N까지의 수로 주어진다.
// 한 파티 내에 진실을 아는 사람-진실을 모르는 사람이 같이 있어서는 안된다.
// 이미 진실을 아는 사람들과 함께 하는 파티에는 무조건 모두가 진실을 알게 된다.
// 한번 파티의 명단을 탐색하여 진실을 알게 될 사람들을 알아낸 후, 다시 한번 명단을 탐색하여 진실을 말하지 않아도 되는 파티를 찾아낸다.
#include <bits/stdc++.h>
using namespace std;
#define MAX 51
enum heard {LIE = -1, IDK = 0, TRUTH = 1};

int N, M;					// 사람의 수, 파티의 수
int truth_teller;						// 진실을 아는 사람의 수
int num, result = 0;
int parent[MAX];
vector<int> teller_list;	// 진실을 아는 사람들의 명단
vector<vector<int>> party_list;			// 파티 명단

void input_data() {
	cin >> N >> M;
	cin >> truth_teller;
	party_list.resize(M);
	for (int i = 0; i < truth_teller; ++i) {
		cin >> num;
		teller_list.push_back(num);
	}
	for (int i = 0; i < M; ++i){
		cin >> num;
		for (int j = 0; j < num; ++j){
			int invite_num;
			cin >> invite_num;
			party_list[i].push_back(invite_num);
		}
	}
	return;
}

int find_parent(int target) {
	if (target == parent[target]) return target;
	return parent[target] = find_parent(parent[target]);
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	parent[b] = a;
}

bool same_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a == b) return true;
	return false;
}

void solution() {
	for (int i = 1; i < N + 1; ++i) parent[i] = i;
	for (int i = 0; i < M; ++i) {
		int N1 = party_list[i][0];
		for (int j = 1; j < party_list[i].size(); ++j) {
			int N2 = party_list[i][j];
			union_parent(N1, N2);
		}
	}
	for (int i = 0; i < M; ++i){
		int available = 1;
		for (int j = 0; j < party_list[i].size(); ++j) {
			if (available == 0) break;
			int N1 = party_list[i][j];
			for (int k = 0; k < teller_list.size(); ++k) {
				int N2 = teller_list[k];
				if (same_parent(N1, N2)){
					available = 0;
					break;
				}
			}
		}
		result += available;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input_data();
	solution();
	cout << result << endl;
	return 0;
}