// �����̰� ���������̷� �˷����� �����鼭, ����� �̾߱⸦ �� �� �ִ� ��Ƽ ������ �ִ��� ���ϴ� ���α׷�
// �����̴� ��� ��Ƽ�� �����ؾ� �Ѵ�.
// ������� ��ȣ�� 1���� N������ ���� �־�����.
// �� ��Ƽ ���� ������ �ƴ� ���-������ �𸣴� ����� ���� �־�� �ȵȴ�.
// �̹� ������ �ƴ� ������ �Բ� �ϴ� ��Ƽ���� ������ ��ΰ� ������ �˰� �ȴ�.
// �ѹ� ��Ƽ�� ����� Ž���Ͽ� ������ �˰� �� ������� �˾Ƴ� ��, �ٽ� �ѹ� ����� Ž���Ͽ� ������ ������ �ʾƵ� �Ǵ� ��Ƽ�� ã�Ƴ���.
#include <bits/stdc++.h>
using namespace std;
#define MAX 51
enum heard {LIE = -1, IDK = 0, TRUTH = 1};

int N, M;					// ����� ��, ��Ƽ�� ��
int truth_teller;						// ������ �ƴ� ����� ��
int num, result = 0;
int parent[MAX];
vector<int> teller_list;	// ������ �ƴ� ������� ���
vector<vector<int>> party_list;			// ��Ƽ ���

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