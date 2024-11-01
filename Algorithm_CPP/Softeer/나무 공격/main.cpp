#include <stdio.h>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int n, m;
int carpenter = 0;
int st, en;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<int> forest(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> carpenter;
			if (carpenter == 1) forest[i]++;
		}
	}
	for (int i = 0; i < 2; i++){
		cin >> st >> en;
		for (int j = st-1; j < en; j++) {
			if (forest[j] > 0) forest[j]--;
		}
	}
	cout << accumulate(forest.begin(), forest.end(), 0) << endl;


}