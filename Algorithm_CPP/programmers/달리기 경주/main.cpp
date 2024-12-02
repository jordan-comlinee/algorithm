#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players; // �ʱ�ȭ
    unordered_map<string, int> player_index; // �÷��̾� �̸��� �ε����� ����

    // �÷��̾� �ε��� �ʱ�ȭ
    for (int i = 0; i < players.size(); ++i) {
        player_index[players[i]] = i;
    }

    // ȣ�� ó��
    for (const string& calling : callings) {
        int idx = player_index[calling]; // ���� ��ġ
        if (idx > 0) {
            // ���� ����
            swap(answer[idx], answer[idx - 1]);
            // �ε��� �� ������Ʈ
            player_index[answer[idx]] = idx;
            player_index[answer[idx - 1]] = idx - 1;
        }
    }

    return answer;
}
