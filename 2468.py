import sys
sys.setrecursionlimit(100000)

n = int(input())
m = []
for i in range(n):
    m.append(list(map(int, input().split())))
# count는 횟수에 대한 수열
count = [] * max(max(m))
stack = []
# print(max(max(m)))
# 좌표에 대해 깊이 우선 탐색
# 좌표가 갈 수 있는 곳을 하나씩 선택해서 전진함(append)
# 만약에 전진할 수 있는 곳이 없다면 다시 되돌아감(pop)
# dfs 재진행
dx, dy = (0, 0, -1, 1),(-1, 1, 0, 0)

def dfs(x, y, h):
    for i in range(4):
        idx = x + dx[i]
        idy = y + dy[i]

        if 0<=idx<n and 0<=idy<n and m[idx][idy] > h and visited[idx][idy] == False:
            visited[idx][idy] = True
            dfs(idx, idy, h)

for height in range(max(max(m))):
    visited = [[False] * n for _ in range(n)]
    safe_area = 0
    for y in range(n):
        for x in range(n):
            if not visited[x][y] and m[x][y] > height:
                safe_area +=1
                visited[x][y] = True
                dfs(x, y, height)

    count.append(safe_area)


print(max(count))