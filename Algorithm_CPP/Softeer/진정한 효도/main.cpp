#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int field[3][3];

int check(int* field) {
	int result = 0;
	sort(field, field + 3);
	result += (field[1] - field[0]) + (field[2] - field[1]);
	return result;
}

int main(void) {
	vector<int> cost;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf_s("%d", &field[i][j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		int hField[3] = { field[0][i], field[1][i], field[2][i] };
		cost.push_back(check(hField));
		cost.push_back(check(field[i]));
	}
	printf("%d", *min_element(cost.begin(), cost.end()));
	return 0;
}

