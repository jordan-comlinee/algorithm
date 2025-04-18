#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// ���� �ð��뿡 ������ �̿��ϴ� ����� m��
// m�� �̸��̶�� ���� ���� �ʿ�X
// �ϳ��� ������ k�ð� ���� ��ϰ�, �� ���Ŀ��� �ݳ�
// players�� ���̴� 24
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < 24; ++i)
    {
        while (q.size() > 0)
        {
            if (i - q.front().second >= k)
            {
                q.pop();
            }
            else {
                break;
            }
        }
        while (true)
        {
            if (players[i] >= m * (q.size() + 1))
            {
                q.push({ k, i });
                answer++;
            }
            else break;
        }
    }
    return answer;
}