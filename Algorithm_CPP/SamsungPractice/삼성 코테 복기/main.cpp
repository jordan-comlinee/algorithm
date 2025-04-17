#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int n, k;

int board[15][15] = { 0 };
int reboard[15][15] = { 0 };

// 3. ����
int third() {
    int total = 0;
    // ������ ��ȣ�� ���� ����
    vector<int> area(k + 1, 0); // ������ ��ȣ�� 1���� k����

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 0) {
                area[board[i][j]]++;
            }
        }
    }

    // cout << "area is ";
    // for(int i : area){
    //     cout << i << ' ';
    // }
    // cout << '\n';

    // �ߺ� ������ pair set
    set<pair<int, int>> checked;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int curr = board[i][j];
            if (curr == 0) continue;

            // ������
            if (j + 1 < n && board[i][j + 1] != 0 && board[i][j + 1] != curr) {
                int next = board[i][j + 1];
                int a = min(curr, next);
                int b = max(curr, next);
                if (checked.find({ a, b }) == checked.end()) {
                    total += area[a] * area[b];
                    checked.insert({ a, b });
                }
            }

            // �Ʒ���
            if (i + 1 < n && board[i + 1][j] != 0 && board[i + 1][j] != curr) {
                int next = board[i + 1][j];
                int a = min(curr, next);
                int b = max(curr, next);
                if (checked.find({ a, b }) == checked.end()) {
                    total += area[a] * area[b];
                    checked.insert({ a, b });
                }
            }
        }
    }

    // cout << "���� ���� : " << total << '\n';
    return total;
}

// 2. ���ġ
void second(int num) {

    // ť ������ ���� ���� ����
    int x_sz, y_sz;
    int min_x = 16, min_y = 16;
    int max_x = 0, max_y = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == num) {
                if (i < min_x) min_x = i;
                if (j < min_y) min_y = j;
                if (i > max_x) max_x = i;
                if (j > max_y) max_y = j;
            }
        }
    }
    x_sz = max_x - min_x + 1;
    y_sz = max_y - min_y + 1;

    // cout << "size is" << x_sz << ' ' << y_sz << '\n';
    // ���ġ ������ ��ǥ ť 

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (reboard[i][j] == 0 && ((n - i) >= x_sz) && (n - j) >= y_sz) {
                q.push({ i,j });
            }
        }
    }

    // int q_sz = q.size();
    // for(int i=0; i<q_sz; i++){
    //     cout << q.front().first << ',' << q.front().second << '\n';
    //     q.pop();
    // }

    // ������ ���
    queue<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == num) {
                points.push({ i,j });
            }
        }
    }
    int points_sz = points.size();

    // cout << "points is \n";
    // for(int i=0; i<points_sz; i++){
    //     cout << points.front().first << points.front().second << '\n';
    //     points.pop();
    // }

    // ���ġ

    int difx = points.front().first - q.front().first;
    int dify = points.front().second - q.front().second;

    // cout << "diff : ";
    // cout << difx << dify << '\n';

    // cout << points.front().first - difx<< points.front().second - dify << '\n';

    for (int i = 0; i < points_sz; i++) {
        reboard[points.front().first - difx][points.front().second - dify] = num;
        points.pop();
    }

    // cout << "visitd : \n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << reboard[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return;
}


// 1. �߰� - ���� ó�� -
bool bfs_visited[6][8];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs(int x, int y, int num) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    bfs_visited[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (bfs_visited[nx][ny] || board[nx][ny] != num) continue;
            bfs_visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }

    return;
}


// 1. �߰�
void first(int num) {

    int sx, sy, fx, fy;
    int x_sz, y_sz;
    cin >> sx >> sy >> fx >> fy;
    x_sz = fx - sx;
    y_sz = fy - sy;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (sx <= i && i <= fx && sy <= j && j <= fy) {
                board[i][j] = num;
            }
        }
    }

    // cout << num << " �߰�\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return;
}


int solution(void) {

    cin >> n >> k;

    for (int numi = 0; numi < k; numi++) {                         // 1 -> k
        // 1. �߰�
        first(numi + 1);

        // 1. �߰� - ���� ó�� -
        for (int target = 1; target < numi + 1; target++) {

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    bfs_visited[i][j] = false;
                }
            }

            // Ÿ�� ���� ����
            int components = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!bfs_visited[i][j] && board[i][j] == target) {
                        bfs(i, j, target);
                        components++;
                        // cout << target << "'s ���� �� : " << components << '\n';
                    }
                }
            }

            // ���� 2�� �̻��̸� ����
            if (components >= 2) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (board[i][j] == target) board[i][j] = 0;
                    }
                }
            }

        }

        // 2. ���ġ �ϱ� �� reboard �ʱ�ȭ 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reboard[i][j] = 0;
            }
        }
        // sumarr �ʱ�ȭ

        vector<int> sumarr(15, 0);

        // ���� ���ġ �� sumarr ���
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 0) {
                    int tmp = board[i][j] - 1;
                    sumarr[tmp] += 1;
                }
            }
        }

        // sumarr ����
        vector<int> sumsort = sumarr;

        sort(sumsort.begin(), sumsort.end());
        reverse(sumsort.begin(), sumsort.end());

        // cout << "sumarr : ";
        // for(int i=0; i<k; i++){
        //     cout << sumarr[i] << ' ';
        // }
        // cout << '\n';

        // cout << "sumsort : ";
        // for(int i=0; i<k; i++){
        //     cout << sumsort[i] << ' ';
        // }
        // cout << '\n';        

        // 2. ���ġ
        // ���ġ ������ ��ȣ ����
        for (int i = 0; i < numi + 1; i++) {
            for (int j = 0; j < numi + 1; j++) {
                if (sumsort[i] == sumarr[j]) {
                    // cout << "target ������ is " << j << '\n';
                    second(j + 1);    // 2. ���ġ
                }
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = reboard[i][j];
            }
        }

        // 3. ����
        cout << third() << ' ';
    }
    cout << '\n';

    return 0;
}

int main(void) {
    freopen("input.txt", "r", stdin);

    int tc = 0;
    cin >> tc;

    while (tc--) {
        cout << "#" << tc + 1 << ' ';
        solution();
    }

    return 0;
}
#endif

#if 1
#include <bits/stdc++.h>
using namespace std;

struct Paper {
    int r1;
    int c1;
    int r2;
    int c2;
    Paper(int r1, int c1, int r2. int c2) : r1(r1), c1(c1), r2(r2), c2(c2) {}
};

const int MAX = 15;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

int T, N, K;
int board[MAX][MAX];
int tmpBoard[MAX][MAX];
vector<Paper> paperInfo;
vector<pair<int, int>> papers;

void inputData();
/// ��ü �ַ��
void solution();

// �߰�
bool isInRange(int x, int y);
vector<pair<int, int>> bfs(int x,  int y);
void putSquare();
void addSquare(int t);
// ��迭
vector<pair<int, int>>  rearrangePapers();

// ���� ���
//void find
bool isNear(int a, int b);
int getScore(vector<pair<int, int>> remains);
//vector<pair<int, int>> 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; ++t) {
        inputData();
        solution();
    }
    
}


void inputData();

/// ��ü �ַ��
void solution() {
    for (int t = 1; t <= T; ++t) {
        vector<int> result;
        addSquare(t);
        vector<pair<int, int>> remains = rearrangePapers();
        getScore(remains);
        cout << "#" << t;
        for (int k = 0; k < K; ++k) {
            cout << " " << result[k];
        }
        cout << endl;

    }
}

// �߰�
bool isInRange(int x, int y);
vector<pair<int, int>> bfs(int x, int y);
void putSquare();
void addSquare(int t);
// ��迭
void putRearrangePaper() {
}
vector<pair<int, int>> rearrangePapers() {
    vector<pair<int, int>> remains;
    // papers.first = ����, papers.second = �ε���*-1 (������ ���� ������ ����)
    sort(papers.begin(), papers.end());
    for (auto paper : papers) {
        // ���� ���� ���� ��ǥ�� �����Ѵ�.
        bool isFirstPoint;
        pair<int, int>  leftUpperPoint;
        vector<pair<int, int>> cuttedSquare;
        // ����� ã�´�.
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == -paper.second) {
                    if (!isFirstPoint) {
                        isFirstPoint = true;
                        leftUpperPoint = { i, j };
                    }
                    cuttedSquare.push_back({ i - leftUpperPoint.first, j - leftUpperPoint.second });
                }
            }
        }
        // ���� ������ �� �� �ִٸ�, �д�
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {

            }
        }
    }
    return remains;
}

// ���� ���
//void find
int getScore(vector<pair<int, int>> remains);
//vector<pair<int, int>> 


#endif