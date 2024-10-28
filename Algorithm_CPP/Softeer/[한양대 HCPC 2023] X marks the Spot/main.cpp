#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<string, string>> puzzle(N);
    string result;
    result.reserve(N * 100);

    for (int i = 0; i < N; i++) {
        cin >> puzzle[i].first >> puzzle[i].second;
    }

    for (int i = 0; i < N; i++) {
        int len = puzzle[i].first.length();
        for (int j = 0; j < len; j++) {
            if ((puzzle[i].first[j] == 'x' || puzzle[i].first[j] == 'X')) {
                result += toupper(puzzle[i].second[j]);
            }
        }
    }

    cout << result << "\n";
    return 0;
}
