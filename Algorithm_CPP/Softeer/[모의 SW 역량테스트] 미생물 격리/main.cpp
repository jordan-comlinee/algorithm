#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int T = 0;
int N, M, K;

pair<int, int> get_direction(int d) {
    if (d == 1) { return make_pair(-1, 0); } // ��
    else if (d == 2) { return make_pair(1, 0); } // ��
    else if (d == 3) { return make_pair(0, -1); } // ��
    else if (d == 4) { return make_pair(0, 1); } // ��
    else { return make_pair(0, 0); }
}

struct germs {
    pair<int, int> location;
    int count;
    int direction;
    germs(int a, int b, int c, int d)
        : location(make_pair(a, b)), count(c), direction(d) {}
};

vector<germs> colonies;

void mergeColonies() {
    map<pair<int, int>, vector<germs>> positionMap;

    // ���� ��ġ���� �׷�ȭ
    for (germs& g : colonies) {
        if (g.count > 0) {
            positionMap[g.location].push_back(g);
        }
    }

    colonies.clear(); // ���� ������ ���� ��ģ �������� ��ü

    for (auto& entry : positionMap) {
        vector<germs>& group = entry.second;
        if (group.size() == 1) {
            colonies.push_back(group[0]);
        }
        else {
            // ���� ������ �ִ� ���
            int maxCount = 0;
            germs mergedGerm = group[0];
            mergedGerm.count = 0; // �ջ� �ʱ�ȭ

            for (germs& g : group) {
                if (g.count > maxCount) {
                    maxCount = g.count;
                    mergedGerm.direction = g.direction; // ���� ������Ʈ
                }
                mergedGerm.count += g.count;
            }
            colonies.push_back(mergedGerm);
        }
    }
}

void solution(int n, int m, int k) {
    colonies.clear();
    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        colonies.push_back(germs(a, b, c, d));
    }

    // M �ð� ���� ����
    for (int i = 0; i < m; i++) {
        map<pair<int, int>, int> newBoard;

        // ���� �̵�
        for (germs& g : colonies) {
            if (g.count > 0) {
                g.location.first += get_direction(g.direction).first;
                g.location.second += get_direction(g.direction).second;

                // ��迡 ����� ��
                if (g.location.first == 0 || g.location.first == n - 1 ||
                    g.location.second == 0 || g.location.second == n - 1) {
                    g.count /= 2;
                    if (g.count > 0) {
                        // ���� ����
                        if (g.direction == 1) g.direction = 2;
                        else if (g.direction == 2) g.direction = 1;
                        else if (g.direction == 3) g.direction = 4;
                        else if (g.direction == 4) g.direction = 3;
                    }
                }
            }
        }
        mergeColonies();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N >> M >> K;
        solution(N, M, K);
        int result = 0;
        for (germs& g : colonies) {
            result += g.count;
        }
        cout << "#" << i << " " << result << endl;
    }
}
