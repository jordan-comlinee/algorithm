#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int N, M;
pair<int, int> out, namwoo;
vector<pair<int, int>> ghosts;
vector<string> maze;
bool escapable = false;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visited[1000][1000] = { false };
bool ghostVisited[1000][1000] = { false };


void isEscapable() {
	if (escapable) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

void printMazeInfo() {
	cout << "===================" << endl;
	for (int i = 0; i < N; i++) {
		cout << maze[i] << endl;
	}
	cout << "===================" << endl;
	cout << "namwoo: " << namwoo.first << " " << namwoo.second << endl;
	cout << "out: "  << out.first << " " << out.second << endl;
	for (pair<int, int> i : ghosts){
		cout << "ghost: " << i.first << " " << i.second << endl;
	}
}

void check(char n, int i, int j) {
	if (n == 'D') {
		out = make_pair(i, j);
	}
	else if (n == 'N') {
		namwoo = make_pair(i, j);
	}
	else if(n == 'G') {
		ghosts.push_back(make_pair(i, j));
	}
}

bool isInRange(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < M && (maze[x][y] == '.' || maze[x][y] == 'D') && !visited[x][y] && !ghostVisited[x][y]) {
		return true;
	}
	else {
		return false;
	}
}void moveGhosts(queue<pair<int, int>>& ghostQueue) {
    int size = ghostQueue.size();
    for (int i = 0; i < size; i++) {
        int x = ghostQueue.front().first;
        int y = ghostQueue.front().second;
        ghostQueue.pop();
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && !ghostVisited[nx][ny]) {
                ghostVisited[nx][ny] = true;
                ghostQueue.push({ nx, ny });
            }
        }
    }
}

void bfs() {
    queue<pair<int, int>> namwooQueue, ghostQueue;
    namwooQueue.push(namwoo);
    visited[namwoo.first][namwoo.second] = true;

    for (pair<int, int> ghost : ghosts) {
        ghostQueue.push(ghost);
        ghostVisited[ghost.first][ghost.second] = true;
    }

    while (!namwooQueue.empty()) {
        int size = namwooQueue.size();

        // 남우 이동
        for (int i = 0; i < size; i++) {
            int x = namwooQueue.front().first;
            int y = namwooQueue.front().second;
            namwooQueue.pop();

            if (x == out.first && y == out.second) {
                escapable = true;
                return;
            }

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (isInRange(nx, ny)) {
                    visited[nx][ny] = true;
                    namwooQueue.push({ nx, ny });
                }
            }
        }

        // 유령 이동
        moveGhosts(ghostQueue);
    }
}




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	maze.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> maze[i];
		for (int j = 0; j < M; j++) {
			check(maze[i][j], i, j);
		}
	}
	bfs();
	isEscapable();
}

