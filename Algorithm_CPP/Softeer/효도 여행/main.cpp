#include<iostream>
#include<vector>

using namespace std;

int n, m, mx;
bool visited[5004];
string str;
vector<pair<int, char>> v[5004]; // 목적지, 간선
int dp[5004][5004];

void go(int here, int d) {
    // 방문 처리
    visited[here] = true;
    // 현재 노드의 리프 노드 존재 검사
    bool isEnd = true;
    for (auto there : v[here]) {
        // 이미 확인한 노드라면 수행X
        if (visited[there.first]) continue;
        isEnd = false;   // 리프노드가 있으므로, 계속해서 dfs로 들어간다.
        for (int i = 1; i <= m; i++) {
            int sum = there.second == str[i - 1] ? 1 : 0; // 동일하면 + 1
            dp[d + 1][i] = max(dp[d][i - 1] + sum, max(dp[d][i], dp[d + 1][i - 1])); // LCS dp를 통해 갯수 확인
        }
        // 리프노드 방문
        go(there.first, d + 1);
        visited[there.first] = false; // dfs 갔다가 돌아옴...방문 취소
    }
    // 만약 리프노드가 없다면
    if (isEnd) {
        for (int i = 0;i <= m;i++) { // 마지막 노드일 때 max값 확인
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