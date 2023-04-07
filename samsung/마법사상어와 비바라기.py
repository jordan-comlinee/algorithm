from collections import deque

# 격자의 크기, 이동 횟수 입력
n, m= map(int, input().split())
# 상어가 연습하는 격자
practice_map = list([[]*(n) for _ in range(n)])
for i in range(n):
        practice_map[i][:] = list(map(int, input().split()))
# 구름이 존재하는 맵 위치
cloudx, cloudy = [n, n, n-1, n-1],[1, 1, 2, 2]
# 비바라기 이동 스킬, [0]은 X
dx, dy = [99, -1, -1, 0, 1, 1, 1, 0, -1],[99, 0, -1, -1, -1, 0, 1, 1, 1]
# 이동 명령을 입력함 d는 방향, s는 거리
rainstorm = deque()
for i in range(m):
    d, s = map(int, input().split())
    rainstorm.append((d,s))
print("====================")
print(rainstorm)
print(len(rainstorm))
print("====================")
# 물복사 마법
def copywater():
    dw, iw = rainstorm.popleft()
    for i in range(iw):
        # 구름이 맵을 넘어가는 경우 반대편으로 보냄
        for j in range(4):
            cloudx[j] = cloudx[j] + dx[dw]
            cloudy[j] = cloudy[j] + dy[dw]
            if cloudx[j] < 0 or cloudx[j] >= n:
                cloudx[j] = abs(n-cloudx[j])
                print(cloudx[j])
            if cloudy[j] < 0 or cloudy[j] >= n:
                cloudy[j] = abs(n-cloudy[j])
                print(cloudy[j])
            practice_map[cloudx[j]][cloudy[j]] += 1

for i in range(m):
    copywater()

print(practice_map)