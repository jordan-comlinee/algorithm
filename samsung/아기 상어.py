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
        # 방문했던 노드를 차례로 꺼낼 수 있도록 함
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
                        visited[ii][jj] = visited[ix][jy] + 1
                        cand.append((visited[ii][jj]-1, ii, jj))
                    elif m[x][y] == m[ii][jj]:
                        visited[ii][jj] = visited[ix][jy] + 1
                        queue.append([ii, jj])
                    elif m[ii][jj] == 0:
                        visited[ii][jj] = visited[ix][jy] + 1
                        queue.append([ii, jj])
            # 후보 리스트는 우선 순위가 있으므로 정렬을 사용함
        return sorted(cand, key = lambda x: (x[0], x[1], x[2]))
    i, j = pos
    size = [2, 0]

    # 맨 앞의 후보만 먹고 위치 이동 후 다시 BFS 반복
    while True:
        m[i][j] = size[0]
        cand = deque(bfs(i, j))

        if not cand:
            break

        # 후보 리스트가 나오면 맨 앞의 후보 먹이를 뽑아 그 위치로 이동함
        step, xx, yy = cand.popleft()
        cnt += step
        size[1] += 1
        # 몇 개를 먹었는 지, 몇 초간 이동했는 지 체크해주기!
        if size[0] == size[1]:
            size[0] += 1
            size[1] = 0
        m[i][j] = 0
        i, j = xx, yy
    return cnt


print(solution())