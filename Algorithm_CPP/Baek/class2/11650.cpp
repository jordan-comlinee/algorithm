#include <bits/stdc++.h>
using namespace std;
// STL sort Ȱ��
// cout << endl;���� endl�� \n�� ����� �ð��� ���̰� ����.
// endl�� ���۸� flush�ϴ� ������ ���ԵǾ��־� �ð��� ���� �� �ɸ���.
// \n�� ���۸� ����� �ʰ�, �״�� ���ܵα� ������ �޸� ȿ������ ����������, �ð��� �� ������.
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
// 1st try : �켱���� ť Ȱ��, �������� ������ Ȱ���ߴ�.
// �������� ���� �� priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
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