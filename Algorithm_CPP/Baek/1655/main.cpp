#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> result;
priority_queue<int> lesser_heap;
priority_queue<int, vector<int>, greater<int>> bigger_heap;


// 1. ���� �Է¹޴´�.
// 2. bigger_heap�� ������ lesser_heap�� �������� 2 �̻� ũ��(¦�� ���� ������), lesser�� top -> mid, mid ->bigger�� top, bigger�� top -> pop
// 3. lesser_heap�� ������ bigger_heap�� �������� ũ�� �ȵ�, bigger�� top -> mid, mid ->lesser�� top, lesser�� top -> pop
void solution() {
	int mid;
	cin >> N;
	result.resize(N);
	cin >> mid;
	result[0] = mid;
	for (int i = 1; i < N; ++i) {
		int num;
		cin >> num;
		if (num > mid) { 
			bigger_heap.push(num); 
		}
		else { 
			lesser_heap.push(num); 
		}
		if (lesser_heap.size() > bigger_heap.size()) {
			bigger_heap.push(mid);
			mid = lesser_heap.top();
			lesser_heap.pop();
		}
		else if (bigger_heap.size() - lesser_heap.size() == 2) {
			lesser_heap.push(mid);
			mid = bigger_heap.top();
			bigger_heap.pop();
		}
		result[i] = mid;

	}
}

void print_result() {
	for (int i = 0; i < N; ++i){
		cout << result[i] << "\n";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solution();
	print_result();
}