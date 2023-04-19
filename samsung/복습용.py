from collections import deque

def solution():
    n = int(input())
    m = [list(map(int, input().split())) for _ in range(n)]
    dx, dy = (0, 0, -1, 1),(-1, 1, 0, 0)

    baby_shark = []
    for y in range(n):
        for x in range(n):
            if m[x][y] == 9:
                baby_shark.append(x)
                baby_shark.append(y)
    print(baby_shark)

    cnt = 0

    def bfs(x, y):
        visited = [[0]*n for _ in range(n)]
        queue = deque((x, y))
        cand = []

        visited[x][y] = 1

        while queue:
            i, j = queue.popleft()

            for a in range(4):
                idx, idy = i + dx[a], j + dy[a]

                if 0<=idx<n and 0<=idy<n and not visited[idx][idy]:
                    if m[x][y] > m[idx][idy] and m[idx][idy] != 0:
                        visited[idx][idy] = visited[i][j] + 1
                        cand.append((visited[idx][idy]-1, idx, idy))
                    elif m[x][y] == m[idx][idy]:
                        visited[idx][idy] = visited[i][j]
solution()