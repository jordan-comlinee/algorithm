#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> bridge(N);
	vector<int> cnt(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &bridge[i]);
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < i; j++) {
			if (bridge[j] < bridge[i]){
				cnt[i] = max(cnt[i], cnt[j] + 1);
			}
			
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d", cnt[i]+1);
	}

	printf("%d", *max_element(cnt.begin(), cnt.end()));

	return 0;
}