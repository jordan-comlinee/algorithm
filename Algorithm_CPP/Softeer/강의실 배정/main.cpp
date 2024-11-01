#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> lecture(N);
	for (int i = 0; i < N; i++)	{
		scanf("%d %d", &lecture[i].second, &lecture[i].first);
	}
	// 빨리 종료하는 것 부터 시작
	sort(lecture.begin(), lecture.end());
	// 끝나는 지점 중, 가장 앞부분부터 시작
	int current = lecture[0].first;
	int cnt = 1;
	// 탐색 시작
	for (int i = 1; i < N; i++) {
		// 이미 채택된 강의의 종료 시간이 탐색 중인 강의의 시작 시간보다 앞일 때, 해당 강의 채택 
		if (current <= lecture[i].second) {
			current = lecture[i].first;
			cnt++;
		}
	}
	printf("%d", cnt);

}