#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> indegree;

void inputData() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.resize(N + 1);
    indegree.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int s;
        cin >> s;
        vector<int> seq(s);
        for (int j = 0; j < s; ++j) {
            cin >> seq[j];
        }
        for (int j = 0; j < s - 1; ++j) {
            int from = seq[j];
            int to = seq[j + 1];
            adj[from].push_back(to);
            indegree[to]++;
        }
    }
}

void solution() {
    queue<int> q;
    vector<int> result;

    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int now = q.front(); q.pop();
        result.push_back(now);
        for (int next : adj[now]) {
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (result.size() != N) {
        cout << 0 << "\n";
    }
    else {
        for (int singer : result) {
            cout << singer << "\n";
        }
    }
}

int main() {
    inputData();
    solution();
    return 0;
}
