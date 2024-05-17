T = int(input())

for t in range(1, T+1) :
    N, M = map(int, input().split())
    line = list()
    for m in range(M):
        x, y = map(int, input().split())
        line.append([x, y])