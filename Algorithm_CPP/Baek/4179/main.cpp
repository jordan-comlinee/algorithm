#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int R, C;
pair<int, int> jihoon;
vector<pair<int, int>> fires;
vector<string> maze;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int visited[1000][1000];
bool fireVisited[1000][1000] = { false };
int maps = 0;

void isEscapable() {
    if (maps > 0) {
        cout << maps << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
}

bool isInRange(int x, int y) {
    return 0 <= x && x < R && 0 <= y && y < C;
}

void moveFire(queue<pair<int, int>>& fireQueue) {
    int size = fireQueue.size();
    for (int i = 0; i < size; i++) {
        int x = fireQueue.front().first;
        int y = fireQueue.front().second;
        fireQueue.pop();
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (isInRange(nx, ny) && !fireVisited[nx][ny] && maze[nx][ny] != '#') {
                fireVisited[nx][ny] = true;
                fireQueue.push({ nx, ny });
            }
        }
    }
}

void bfs() {
    queue<pair<int, int>> jihoonQueue, fireQueue;
    jihoonQueue.push(jihoon);
    visited[jihoon.first][jihoon.second] = 1;  // 지훈 시작 위치를 1로 초기화
    for (pair<int, int> fire : fires) {
        fireQueue.push(fire);
        fireVisited[fire.first][fire.second] = true;
    }

    while (!jihoonQueue.empty()) {
        // 불 이동
        moveFire(fireQueue);

        int size = jihoonQueue.size();

        // 지훈 이동
        for (int i = 0; i < size; i++) {
            int x = jihoonQueue.front().first;
            int y = jihoonQueue.front().second;
            jihoonQueue.pop();

            // 미로의 가장자리라면 탈출 가능
            if (x == R - 1 || y == C - 1 || x == 0 || y == 0) {
                maps = visited[x][y];
                return;
            }

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (isInRange(nx, ny) && maze[nx][ny] == '.' && visited[nx][ny] == 0 && !fireVisited[nx][ny]) {
                    visited[nx][ny] = visited[x][y] + 1;
                    jihoonQueue.push({ nx, ny });
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    maze.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> maze[i];
        for (int j = 0; j < C; j++) {
            visited[i][j] = 0;  // 방문 여부 초기화
            if (maze[i][j] == 'J') {
                jihoon = make_pair(i, j);
            }
            else if (maze[i][j] == 'F') {
                fires.push_back(make_pair(i, j));
            }
        }
    }
    bfs();
    isEscapable();
}
