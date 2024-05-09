def rotate_90(N, maze):
    result = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            result[j][N-1-i] = maze[i][j]
    return result

T = int(input())

for t in range(1, T+1):
    N = int(input())
    result = [['','',''] for _ in range(N)]
    maze = [list(map(int, input().split())) for _ in range(N)]
    for i in range(3):
        maze = rotate_90(N, maze)
        for j in range(N):
            r_str = ''
            for n in maze[j] : r_str += str(n)
            result[j][i] = r_str
    print(f"#{t}")
    for n in range(N):
        for m in range(3):
            print(result[n][m], end=' ')
        print()
