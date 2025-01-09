#include <bits/stdc++.h>
using namespace std;
// STL sort 활용
// cout << endl;에서 endl과 \n의 입출력 시간이 차이가 난다.
// endl은 버퍼를 flush하는 과정이 포함되어있어 시간이 조금 더 걸린다.
// \n은 버퍼를 비우지 않고, 그대로 남겨두기 때문에 메모리 효율성은 떨어지지만, 시간이 더 빠르다.
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
		cout << n_arr[i].first << " " << n_arr[i].second << "\n";
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
		cout << n_arr.top().first<< " " << n_arr.top().second << "\n";
		n_arr.pop();
	}
}
#endif