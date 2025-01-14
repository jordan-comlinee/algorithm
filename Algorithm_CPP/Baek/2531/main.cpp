#include<bits/stdc++.h>
using namespace std;
// 시간 초과 문제
/*
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int result = 0;
	int N, d, k, c;
	cin >> N >> d >> k >> c;
	vector<int> sushi;
	for (int i = 0; i < N; ++i)
	{
		int piece;
		cin >> piece;
		sushi.push_back(piece);
	}
	for (int i = 0; i < k-1; i++) {
		sushi.push_back(sushi[i]);
	}
	for (int i = 0; i < N; i++){
		set<int> sushi_set;
		for (int j = 0; j < k; j++) {
			sushi_set.insert(sushi[i + j]);
		}
		sushi_set.insert(c);
		result = result < sushi_set.size() ? sushi_set.size() : result;
		if (result == k+1) {
			break;
		}
	}
	printf("%d\n", result);
	return 0;
}
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, d, k, c; // 접시 수, 초밥 가짓수, 연속해서 먹는 수, 쿠폰 초밥 번호
    cin >> N >> d >> k >> c;
    vector<int> sushi(N);
    for (int i = 0; i < N; ++i) {
        cin >> sushi[i];
    }
    map<int, int> sushi_count;
    int current_unique = 0;             // 초밥 종류 수
    int result = 0;
    for (int i = 0; i < k; ++i) {
        if (sushi_count[sushi[i]] == 0) current_unique++;
        sushi_count[sushi[i]]++;
    }
    result = current_unique + (sushi_count[c] == 0 ? 1 : 0);
    for (int i = 0; i < N; ++i) {
        int start = i;
        int end = (i + k) % N;
        if (--sushi_count[sushi[start]] == 0) {
            current_unique--;
        }
        if (sushi_count[sushi[end]]++ == 0) {
            current_unique++;
        }

        // 결과 갱신
        result = max(result, current_unique + (sushi_count[c] == 0 ? 1 : 0));
    }

    cout << result << '\n';
    return 0;
}
