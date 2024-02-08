from collections import deque
import copy

n, m = map(int, input().split())
lab_map = [list(map(int, input().split())) for _ in range(n)]
# 정답
result = 0
# 벽을 세운 횟수
wall_count = 0

# 벽을 세운 후, 빈칸을 세는 시뮬레이션 진행
def simulation(count):
    # 만약에 모든 벽을 세웠다면, bfs(바이러스 전염)을 통해 시뮬레이션 시작
    if count == 3:
        # bfs()내부의 글로벌 변수를 통해 안전한 구역의 수를 확인할 수 있음
        bfs()
        return
    # 맵의 부분부분에 대해서 벽 하나씩 세워본다
    for i in range(n):
        for j in range(m):
            # 만약 맵의 한 좌표에 아직 벽이 안세워져있고, 3개를 다 채우지 못한 경우
            if lab_map[i][j] == 0:
                # 벽을 세운다
                lab_map[i][j] = 1
                # 하나 더 세웠으니 count + 1, 시뮬 다시 한다 -->
                simulation(count+1)
                # simulation() 함수를 통해 벽 3개를 다 세우고, bfs()로 시뮬까지 돌렸음....그러므로 아까 세운 거 다 없앰
                lab_map[i][j] = 0

dx, dy = [0, 0, -1, 1],[-1, 1, 0, 0]
def bfs():
    visited = deque()
    virtual_map = copy.deepcopy(lab_map)
    for i in range(n):
        for j in range(m):
            #if virtual_map[i][j] =