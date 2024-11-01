#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<pair<string, string>> puzzle(N);
	string result = "";
	for (int i = 0; i < N; i++) {
		string first, second;
		scanf("%s %s", first, second);
		puzzle[i] = make_pair(first, second);
	}
	for (int i = 0; i < N; i++)
	{
		int len = puzzle[i].first.length();
		for (int j = 0; j < len; j++) {
			if (puzzle[i].first[j] == 'x' || puzzle[i].first[j] == 'X') {
				result += toupper(puzzle[i].second[j]);
			}
		}
	}
	printf("%s", result.c_str());
}
