from collections import deque
import copy
n, m = map(int, input().split())
block = []
for i in range(n):
    block.append(list(map(int, input().split())))
score = 0
# 블록 그룹을 검사하기 위해 bfs를 수행한다.
dx, dy = (0, 0, -1, 1),(-1, 1, 0, 0)
def find_block(i, j, block_num):
    visit = deque()
    visit.append((i, j))

    normalBlocks = [[i, j]]
    rainbowBlocks = []

    while visit:
        x, y = visit.popleft()

        for i in range(4):
            idx = x + dx[i]
            idy = y + dy[i]

            if 0<= idx < n and 0 <= idy < n:
                # 무지개 블록을 만난 경우
                if block[idx][idy] == 0 and not visited[idx][idy]:
                    visit.append((idx, idy))
                    rainbowBlocks.append([idx, idy])
                    visited[idx][idy] = 1

                elif block[idx][idy] == block_num and not visited[idx][idy]:
                    visit.append((idx, idy))
                    normalBlocks.append([idx, idy])
                    visited[idx][idy] = 1
    # 다른 블록들 탐색할 때 무지개를 포함시켜야 하므로
    for x, y in rainbowBlocks:
        visited[x][y] = 0

    return [len(normalBlocks + rainbowBlocks), len(rainbowBlocks), normalBlocks + rainbowBlocks]

# find_block에서 찾은 모든 블록 제거 / group[0] = 개수 group[1] = rainbow 블럭 개수 / group[2] = 블럭 위피
def remove_block(group):
    global score
    # 점수 계산
    score += (group[0] ** 2)

    # 제거된 블록은 -2로 표시한다.
    for x, y in group[2]:
        block[x][y] = -2

# 중력 작용
def gravity():
    for i in range(n-2, -1, -1):
        for j in range(n):
            if block[i][j] != -1:
                pointer = i

                while pointer + 1 < n and block[pointer + 1][j] == -2:
                    block[pointer+1][j] = block[pointer][j]
                    block[pointer][j] = -2
                    pointer += 1


def rotate_block():
    global block
    tmp = [[0]*n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            tmp[n-j-1][i] = block[i][j]
    block = tmp

while True:
    visited = [[0] * n for _ in range(n)]
    groups = []
    for i in range(n):
        for j in range(n):
            if block[i][j] >= 1 and not visited[i][j]:
                visited[i][j] = 1
                group = find_block(i, j, block[i][j])

                if group[0] >=2:
                    groups.append(group)
    groups.sort(reverse=True)

    if not groups:
        break

    remove_block(groups[0])
    gravity()
    rotate_block()
    gravity()
print(score)


