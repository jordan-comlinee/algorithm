#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int N, S;
int result = INF;				// 정답
vector<int> num_arr;

void input_data(void) {
	cin >> N >> S;
	num_arr.resize(N);
	for (int i = 0; i < N; ++i){
		cin >> num_arr[i];
	}
	return;
}

void solution() {
	int start_p = 0, end_p = 0;		// 투포인터
	int sum = 0;
	while (end_p < N) {
		sum += num_arr[end_p++];
		while (sum >= S) {
			result = min(result, end_p - start_p);
			sum -= num_arr[start_p++];
		}
	}
	if (result == INF) {
		result = 0;
	}
	return;
}

//void solution() {
//	int sum = 0;
//	for (int i = 0; i < N; ++i) {
//		sum = num_arr[i];
//		for (int j = i + 1; j < N; ++j) {
//			sum += num_arr[j];
//			if (sum >= S) {
//				result = result > j - i + 1 ? j - i + 1 : result;
//				break;
//			}
//		}
//		if (result == 1) {
//			break;
//		}
//	}
//	if (result == INF) {
//		result = 0;
//	}
//	return;
//}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input_data();
	solution();
	cout << result << endl;
	return 0;
}