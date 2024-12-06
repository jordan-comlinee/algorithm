from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(x, y, land, visited):
    q = deque()
    oil_range = set()
    amount = 1
    h = len(land)
    w = len(land[0])
    q.append((x, y))
    oil_range.add(y)

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if (nx >= 0 and nx < h and ny >= 0 and ny < w and land[nx][ny] == 1 and not visited[nx][ny]):
                visited[nx][ny] = True
                amount += 1
                oil_range.add(ny)
                q.append((nx, ny))
    return amount, oil_range


def solution(land):
    h = len(land)
    w = len(land[0])
    answer = [0 for _ in range(w)]
    visited = [[False for _ in range(w)] for _ in range(h)]
    for x in range(h):
        for y in range(w):
            if land[x][y] == 1 and visited[x][y] == False:
                visited[x][y] = True
                amount, oil_range = bfs(x, y, land, visited)
                for i in oil_range:
                    answer[i] += amount

    return max(answer)

solution([[0, 0, 0, 1, 1, 1, 0, 0], [0, 0, 0, 0, 1, 1, 0, 0], [1, 1, 0, 0, 0, 1, 1, 0], [1, 1, 1, 0, 0, 0, 0, 0], [1, 1, 1, 0, 0, 0, 1, 1]])