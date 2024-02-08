from collections import deque
import copy

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
result = 0
wall_count = 0

# 벽을 세운 후, 빈칸을 세는 시뮬레이션 진행
def simulation(count):
    if count == 3:
        bfs()
        return
    for i in range(n):
        for j in range(m):
            if board[i][j] == 0:
                board[i][j] = 1
                simulation(count+1)
                board[i][j] = 0
# 상 하 좌 우
dx, dy = [0, 0, -1, 1],[-1, 1, 0, 0]
def bfs():
    queue = deque()
    test_board = copy.deepcopy(board)
    for i in range(n):
        for j in range(m):
            if test_board[i][j] == 2:
                queue.append((i, j))

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            idx = x + dx[i]
            idy = y + dy[i]
            if idx <0 or idy <0 or idx >= n or idy >= m:
                continue
            if test_board[idx][idy] == 0:
                test_board[idx][idy] = 2
                queue.append((idx, idy))
        global result
        count = 0
    for i in range(n):
        for j in range(m):
            if test_board[i][j] == 0:
                count +=1
    result = max(result, count)

simulation(wall_count)
print(result)