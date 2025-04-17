#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int MAX = 75;
int R, C, K;
int arr[MAX][MAX]; // 맵
int visited[MAX][MAX];
int di[4] = { -1, 0, 1, 0 }; // 상우하좌
int dj[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> unit; // {cj, dir}
set<pair<int, int>> exit_set;

int bfs(int si, int sj) {
    queue<pair<int, int>> q;
    int max_i = 0;
    fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);

    q.push({ si, sj });
    visited[si][sj] = 1;

    while (!q.empty()) {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();
        max_i = max(max_i, ci);

        for (int d = 0; d < 4; ++d) {
            int ni = ci + di[d];
            int nj = cj + dj[d];

            if (!visited[ni][nj] &&
                (arr[ci][cj] == arr[ni][nj] ||
                    (exit_set.count({ ci, cj }) && arr[ni][nj] > 1))) {
                visited[ni][nj] = 1;
                q.push({ ni, nj });
            }
        }
    }
    return max_i - 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> K;
    unit.resize(K);
    for (int i = 0; i < K; ++i) {
        int cj, dr;
        cin >> cj >> dr;
        unit[i] = { cj, dr };
    }

    int ans = 0;
    int num = 2;

    // 배열 초기화
    for (int i = 0; i < R + 3; ++i) {
        for (int j = 0; j < C + 2; ++j) {
            arr[i][j] = (j == 0 || j == C + 1) ? 1 : 0;
        }
    }
    for (int j = 0; j < C + 2; ++j) arr[R + 3][j] = 1;

    for (auto uni : unit) {
        int cj = uni.first;
        int dr = uni.second;
        int ci = 1;

        while (true) {
            // 남쪽으로 이동
            if (arr[ci + 1][cj - 1] + arr[ci + 2][cj] + arr[ci + 1][cj + 1] == 0) {
                ci++;
            }
            // 서쪽 회전 후 이동
            else if (arr[ci - 1][cj - 1] + arr[ci][cj - 2] + arr[ci + 1][cj - 1] +
                arr[ci + 1][cj - 2] + arr[ci + 2][cj - 1] == 0) {
                ci++;
                cj--;
                dr = (dr + 3) % 4;
            }
            // 동쪽 회전 후 이동
            else if (arr[ci - 1][cj + 1] + arr[ci][cj + 2] + arr[ci + 1][cj + 1] +
                arr[ci + 1][cj + 2] + arr[ci + 2][cj + 1] == 0) {
                ci++;
                cj++;
                dr = (dr + 1) % 4;
            }
            else {
                break;
            }
        }

        if (ci < 4) {
            // 다시 초기화
            for (int i = 0; i < R + 3; ++i) {
                for (int j = 0; j < C + 2; ++j) {
                    arr[i][j] = (j == 0 || j == C + 1) ? 1 : 0;
                }
            }
            for (int j = 0; j < C + 2; ++j) arr[R + 3][j] = 1;

            exit_set.clear();
            num = 2;
        }
        else {
            // 골렘 표시
            arr[ci + 1][cj] = arr[ci - 1][cj] = num;
            arr[ci][cj - 1] = arr[ci][cj] = arr[ci][cj + 1] = num;
            exit_set.insert({ ci + di[dr], cj + dj[dr] });
            ans += bfs(ci, cj);
            num++;
        }
    }

    cout << ans << '\n';
    return 0;
}
#endif