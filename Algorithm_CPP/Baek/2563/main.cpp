#if 0
// ��ȭ���� ũ��� �������� ������ ������ �ְ�, �� ���� ���� ������ �������� ũ�Ⱑ ������ �ֱ� ������ simulation���� �����ص� �� �� ����.
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int main() {
	// cin ����� �ӵ� ���� ����
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, maps = 0;							// t = ������ ����, maps = ����(��)
	bool dohwaji[MAX + 1][MAX + 1] = { false };	// ��ȭ��
	vector<pair<int, int>> paper(MAX);			// �� �������� ��ġ

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> paper[i].first >> paper[i].second;
	}

	// t�� max = 100, x = 10, y = 10, �ִ� ���� = 100*10*10 = 10000ȸ
	for (int i = 0; i < t; i++) {
		int X = paper[i].first;					// �� �������� x ��ǥ
		int Y = paper[i].second;				// �� �������� y ��ǥ
		for (int x = 0; x < 10; ++x) {
			for (int y = 0; y < 10; ++y) {
				if (!dohwaji[X + x][Y + y]) {
					dohwaji[X + x][Y + y] = true;
					++maps;
				}
			}
		}
	}
	cout << maps << endl;
	return 0;
}
#endif