def make_snail(N) :
    global snail
    x, y, d = 0, 0, 4
    move = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    for i in range(1, N*N+1) :
        snail[x][y] = i
        if (0 <= x+move[d%4][0] < N and 0 <= y+move[d%4][1] < N and snail[x+move[d%4][0]][y+move[d%4][1]] == 0) :
            x += move[d%4][0]
            y += move[d%4][1]
        else:
            d += 1
            x += move[d%4][0]
            y += move[d%4][1]

T = int(input())

for t in range(1, T+1) :
    N = int(input())
    snail = [[0]*N for _ in range(N)]
    make_snail(N)
    print(f"#{t}")
    for i in range(N):
        for j in range(N):
            print(f"{snail[i][j]}", end=" ")
        print()