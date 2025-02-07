#include<iostream>
#include<vector>

using namespace std;

int n, m, mx;
bool visited[5004];
string str;
vector<pair<int, char>> v[5004]; // ������, ����
int dp[5004][5004];

void go(int here, int d) {
    // �湮 ó��
    visited[here] = true;
    // ���� ����� ���� ��� ���� �˻�
    bool isEnd = true;
    for (auto there : v[here]) {
        // �̹� Ȯ���� ����� ����X
        if (visited[there.first]) continue;
        isEnd = false;   // ������尡 �����Ƿ�, ����ؼ� dfs�� ����.
        for (int i = 1; i <= m; i++) {
            int sum = there.second == str[i - 1] ? 1 : 0; // �����ϸ� + 1
            dp[d + 1][i] = max(dp[d][i - 1] + sum, max(dp[d][i], dp[d + 1][i - 1])); // LCS dp�� ���� ���� Ȯ��
        }
        // ������� �湮
        go(there.first, d + 1);
        visited[there.first] = false; // dfs ���ٰ� ���ƿ�...�湮 ���
    }
    // ���� ������尡 ���ٸ�
    if (isEnd) {
        for (int i = 0;i <= m;i++) { // ������ ����� �� max�� Ȯ��
            mx = max(mx, dp[d][i]);
        }
    }
}

int main(int argc, char** argv)
{
    cin >> n >> m;
    cin >> str;
    int s, d;
    char e;
    for (int i = 0; i < n - 1; i++) {
        cin >> s >> d >> e;
        v[s].push_back({ d ,e });
        v[d].push_back({ s ,e });
    }
    go(1, 0);
    cout << mx;
    return 0;
}