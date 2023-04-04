# https://hardenkim.tistory.com/39
from collections import deque

def solution():
    n, m = map(int, input().split())
    b = [list(input().strip()) for i in range(n)]
    dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
    q = deque()
    # 구슬이 들렸던 위치를 저장함
    visited = [[[[False]*m for i in range(n)] for i in range(m)]for i in range(n)]

    # 초기 구슬의 좌표를 저장함
    def init():
        rx, ry, bx, by = 0, 0, 0, 0
        for i in range(n):
            for j in range(m):
                if b[i][j] == 'R':
                    rx, ry = i, j
                elif b[i][j] == 'B':
                    bx, by = i, j
        # 구슬의 위치와 depth를 저장함
        q.append((rx, ry, bx, by, 1))
        # 구슬의 위치를 기록함
        visited[rx][ry][bx][by] = True

    def move(x, y, dx, dy):
        # 이동 칸 수
        cnt = 0
        # 이동했을 때, 벽이 아니고 구멍이 아닐 때까지 이동함
        while b[x+dx][y+dy] != '#' and b[x][y] != 'O':
            x += dx
            y += dy
            cnt += 1
        return x, y, cnt

    def bfs():
        init()
        while q:
            rx, ry, bx, by, cnt = q.popleft()
            if cnt > 10:
                return -1
            # 4방향, 상-하-좌-우
            for i in range(4):
                nrx, nry, nrc = move(rx, ry, dx[i], dy[i])
                nbx, nby, nbc = move(bx, by, dx[i], dy[i])
                if b[nbx][nby] != 'O':
                    if b[nrx][nry] == 'O':
                        return cnt
                    if nrx == nbx and nry == nby:
                        if nrc > nbc:
                            nrx -= dx[i]
                            nry -= dy[i]
                        else:
                            nbx -= dx[i]
                            nby -= dy[i]
                    if visited[nrx][nry][nbx][nby] == False:
                        visited[nrx][nry][nbx][nby] = True
                        q.append((nrx, nry, nbx, nby, cnt+1))
        return -1

    return bfs()


print(solution())
