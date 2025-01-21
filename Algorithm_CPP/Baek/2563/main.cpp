#if 0
// 도화지의 크기와 색종이의 개수가 정해져 있고, 그 수가 많지 않으며 색종이의 크기가 정해져 있기 때문에 simulation으로 진행해도 될 것 같다.
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int main() {
	// cin 입출력 속도 문제 개선
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, maps = 0;							// t = 색종이 개수, maps = 면적(답)
	bool dohwaji[MAX + 1][MAX + 1] = { false };	// 도화지
	vector<pair<int, int>> paper(MAX);			// 각 색종이의 위치

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> paper[i].first >> paper[i].second;
	}

	// t의 max = 100, x = 10, y = 10, 최대 연산 = 100*10*10 = 10000회
	for (int i = 0; i < t; i++) {
		int X = paper[i].first;					// 각 색종이의 x 좌표
		int Y = paper[i].second;				// 각 색종이의 y 좌표
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