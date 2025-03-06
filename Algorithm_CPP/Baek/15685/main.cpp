
#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
// 드래곤 커브의 개수
int N = 0;
// 드래곤 커브의 정보 : x, y = 시작점, d = 시작 방향, g = 세대
int x, y, d, g;
int map[MAX][MAX] = { 0 };

void inputData();
void dragonCurve();

int main() {
	inputData();
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y >> d >> g;
	}
}

void dragonCurve() {
}