from collections import deque

def solution():
    # 상, 하, 좌, 우
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    # 맵의 크기
    n = int(input())
    # 사과의 개수
    apple = int(input())
    # 맵 지정
    b = [[0]*n for i in range (n)]
    for i in range(apple):
        ax, ay = map(int, input().split())
        if ax == 0 and ay == 0:
            return -1
        b[ax][ay] = 1
    # 뱀
    snake = deque()
    snake.append((1, 1))
    # 뱀 방향 변환 횟수
    l = int(input())
    time = {}
    for i in range(l):
        x, c = input().split()
        time[int(x)] = c
    print(time)
    print(len(time))
    def move(n, b, snake, time):
        # 뱀 머리 위치
        sx, sy = 0, 0
        cnt = 0
        d = 3
        while True:
            for i in range(1, len(time)+1):
                # 사과가 있는 경우
                if b[sx][sy] == 1:
                    snake.append((sx, sy))
                    b[sx][sy] == 0
                # 사과를 안먹은 경우
                if len(snake) == 1:
                    if time[i] == 'L':
                        d = (d-1) % 4
                        sx, sy = sx + dx[d], sy + dy[d]
                    elif time[i] == 'D':
                        d = (d+1) % 4
                        sx, sy = sx + dx[d], sy + dy[d]
                    else:
                        sx, sy = sx + dx[d], sy + dy[d]
                    if sx >= n or sy >= n:
                        return cnt
                    snake[0] = (sx, sy)
                # 사과를 먹은 경우
                else:
                    if time[i] == 'L':
                        d = (d - 1) % 4
                        sx, sy = sx + dx[d], sy + dy[d]
                    elif time[i] == 'D' :
                        d = (d+1) % 4
                        sx, sy = sx + dx[d], sy + dy[d]
                    else:
                        sx, sy = sx + dx[d], sy + dy[d]
                    if sx >= n or sy >= n:
                        return cnt
                    snake.popleft()
                    snake.append((sx, sy))
                cnt+=1

    return move(n, b, snake, time)

print(solution())