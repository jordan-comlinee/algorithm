#include <bits/stdc++.h>
using namespace std;

typedef struct _snowpoint {
	int leftP;
	int rightP;
} snowP;

int N;
vector<int> snowballs;
int result = INT32_MAX;
int rightP, leftP;
int sub;

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
			//cout << i << " " << j << endl;
			result = min(result, findSmallest(i, j, snowballs));
			//cout << "==========================" << endl;
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
		cur = abs(annaSnowballs[anna.leftP] + annaSnowballs[anna.rightP]-elzaHap);
		diff = min(cur, diff);
		if (annaSnowballs[anna.leftP] + annaSnowballs[anna.rightP] - elzaHap < 0) {
			anna.leftP++;
		}
		else if (annaSnowballs[anna.leftP] + annaSnowballs[anna.rightP] - elzaHap > 0) {
			anna.rightP--;
		}
		else { 
			//cout << 0 << endl;
			return 0;
		}
	}
	//cout << elzaHap << " " << diff << endl;
	return diff;
}