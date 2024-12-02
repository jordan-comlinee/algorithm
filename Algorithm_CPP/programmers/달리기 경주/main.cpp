#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players; // 초기화
    unordered_map<string, int> player_index; // 플레이어 이름과 인덱스를 매핑

    // 플레이어 인덱스 초기화
    for (int i = 0; i < players.size(); ++i) {
        player_index[players[i]] = i;
    }

    // 호출 처리
    for (const string& calling : callings) {
        int idx = player_index[calling]; // 현재 위치
        if (idx > 0) {
            // 순서 변경
            swap(answer[idx], answer[idx - 1]);
            // 인덱스 맵 업데이트
            player_index[answer[idx]] = idx;
            player_index[answer[idx - 1]] = idx - 1;
        }
    }

    return answer;
}
