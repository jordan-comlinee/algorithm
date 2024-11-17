#include <bits/stdc++.h>
using namespace std;

vector<int> boxes = vector<int>(100, 0);
int result, cnt;

void flatten() {
	for (int i = 0; i < cnt; i++){
		int minIdx = min_element(boxes.begin(), boxes.end()) - boxes.begin();
		int maxIdx = max_element(boxes.begin(), boxes.end()) - boxes.begin();

		boxes[minIdx]++;
		boxes[maxIdx]--;

	}
	result = *max_element(boxes.begin(), boxes.end()) - *min_element(boxes.begin(), boxes.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int t = 1; t <= 10; t++){
		result = 0;
		cin >> cnt;
		for (int i = 0; i < 100; i++){
			cin >> boxes[i];
		}
		flatten();
		cout << "#" << t << " " << result << endl;
	}
}