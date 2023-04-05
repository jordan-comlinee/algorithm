from collections import deque

# 기본 입력값 (graph : 2차원 평면, visited : 2차원 체커)
N = int(input())
graph = []
visited = [[False]*N for i in range(N)]
cnt = 0

# graph에 아파트 위치 입력
for i in range(N):
    line = list(map(int, input()))
    graph.append(line)

# bfs 정의
def bfs(x, y):
    cnt = 0
    dx = [0,0,-1,1]
    dy = [1,-1,0,0]

    queue = deque()

    if graph[y][x] == 1:
        queue.append((x, y))
        visited[y][x] = True
        cnt += 1

        while queue:
            x, y = queue.popleft()

            for i in range(4):
                nx = x+dx[i]
                ny = y+dy[i]

                if 0<=nx<N and 0<=ny<N:
                    if graph[ny][nx]==1 and visited[ny][nx]==False:
                        queue.append((nx,ny))
                        visited[ny][nx] = True
                        cnt += 1
    return cnt

li = []

for i in range(N):
    for j in range(N):
        if graph[j][i] == 1 and visited[j][i]==False:
            li.append(bfs(i, j))

print(len(li))
for i in sorted(li):
    print(i)