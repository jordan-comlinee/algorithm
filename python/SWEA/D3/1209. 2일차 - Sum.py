for _ in range(10):
    t = int(input())
    maze = [list(map(int, input().split()))[:100] for _ in range(100)]
    score_list = []
    sum2 = 0
    sum3 = 0
    for i in range(100):
        # 열
        sum0 = 0
        # 행
        sum1 = sum(maze[i])
        score_list.append(sum1)
        # 대각선1
        sum2 += maze[i][i]
        # 대각선2
        sum3 += maze[i][99-i]
        for j in range(100):
            sum0 += maze[j][i]
        score_list.append(sum0)
    score_list.append(sum2)
    score_list.append(sum3)
    print(f"#{t} {max(score_list)}")

