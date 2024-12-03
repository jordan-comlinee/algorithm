#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end());
    int answer = 0;
    int idx = 0;
    while (idx < targets.size()) {
        int end = targets[idx++][1];
        answer++;
        while (idx < targets.size() && targets[idx][0] < end) {
            if (targets[idx][1] < end) {
                end = targets[idx][1];
            }
            idx++;
        }
    }
    return answer;
}