from collections import deque

def solution():
    n = int(input())
    m = [list(map(int, input().split())) for i in range(n)]
    dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]

    pos = []
    for i in range(n):
        for j in range(n):
            if m[i][j] == 9:
                pos.append(i)
                pos.append(j)
    cnt = 0
    # 가까운 먹이를 찾는 탐색 알고리즘으로, BFS를 생각할 수 있음
    # 입력으로 현재 아기 상어의 위치를 넣고, 반환으로 후보 리스트를 반환함.
    def bfs(x, y):
        """넓이 탐색 알고리즘"""
        # 방문했던 맵
        visited = [[0]*n for i in range(n)]
        queue = deque([x, y])
        # ??
        cand = []

        while queue:
            ix, jy = queue.popleft()

            for idx in range(4):
                ii,jj = ix+dx(idx), jy + dy[idx]
                # visited[ii][jj] 안에 있고 visited[ii][jj]가 아직 방문하지 않은 노드인 경우!
                if 0 <= ii < n and 0 <= j < n and visited[ii][jj] == 0:
                    if m[x][y] > m[x][y] and m[ii][jj] != 0:
                        visited[ii][jj] =



solution()