#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#if 0
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, x, y;
	cin >> N;
	vector<pair<int, int>> n_arr;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		n_arr.push_back({x, y});
	}
	sort(n_arr.begin(), n_arr.end());
	for (int i = 0; i < N; i++) {
		cout << n_arr[i].first << " " << n_arr[i].second << endl;
	}
	return 0;
}
#endif
// 1st try : 우선순위 큐 활용, 오름차순 정렬을 활용했다.
// 오름차순 정렬 시 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
#if 0
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> n_arr;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		n_arr.push(make_pair(x, y));
	}
	for (int i = 0; i < N; i++) {
		cout << n_arr.top().first<< " " << n_arr.top().second << endl;
		n_arr.pop();
	}
}
#endif