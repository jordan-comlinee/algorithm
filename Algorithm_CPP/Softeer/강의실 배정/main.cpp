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
	// ���� �����ϴ� �� ���� ����
	sort(lecture.begin(), lecture.end());
	// ������ ���� ��, ���� �պκк��� ����
	int current = lecture[0].first;
	int cnt = 1;
	// Ž�� ����
	for (int i = 1; i < N; i++) {
		// �̹� ä�õ� ������ ���� �ð��� Ž�� ���� ������ ���� �ð����� ���� ��, �ش� ���� ä�� 
		if (current <= lecture[i].second) {
			current = lecture[i].first;
			cnt++;
		}
	}
	printf("%d", cnt);

}