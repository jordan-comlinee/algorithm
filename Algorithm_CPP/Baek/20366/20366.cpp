#include <bits/stdc++.h>
using namespace std;

typedef struct _snowpoint {
	int leftP;
	int rightP;
} snowP;

int N;
vector<int> snowballs;
int result = INT32_MAX;

void inputData();
void solution();
int findSmallest(int a, int b, vector<int> annaSnowballs);

int main() {
	inputData();
	solution();
	cout << result << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int snowball;
		cin >> snowball;
		snowballs.push_back(snowball);
	}
}

void solution() {
	sort(snowballs.begin(), snowballs.end());
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			result = min(result, findSmallest(i, j, snowballs));
		}
	}
	
}

int findSmallest(int a, int b, vector<int> annaSnowballs) {
	int diff = INT32_MAX;
	int cur = 0;
	int elzaHap = snowballs[a] + snowballs[b];
	annaSnowballs.erase(annaSnowballs.begin() + a);
	annaSnowballs.erase(annaSnowballs.begin() + b-1);

	snowP anna = { 0, annaSnowballs.size()-1};
	while (anna.leftP < anna.rightP) {
		cur = annaSnowballs[anna.leftP] + annaSnowballs[anna.rightP]-elzaHap;
		diff = min(abs(cur), diff);
		if (cur < 0) anna.leftP++;
		else if (cur > 0) anna.rightP--;
		else return 0;
	}
	return diff;
}