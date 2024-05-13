def dfs(index, score, kcal):
    global maxScore

    if kcal > L:
        return
    if maxScore < score :
        maxScore = score

    if index == N :
        return

    sScore = score_list[index]
    sKcal = kcal_list[index]
    dfs(index+1, score+sScore, kcal+sKcal)

    dfs(index+1, score, kcal)

T = int(input())

for t in range(1, T+1) :
    N, L = map(int, input().split())
    score_list = [0 for _ in range(N)]
    kcal_list = [0 for _ in range(N)]
    for i in range(N):
        score_list[i], kcal_list[i] = map(int, input().split())
    maxScore = 0
    dfs(0, 0, 0)
    print(f"#{t} {maxScore}")
