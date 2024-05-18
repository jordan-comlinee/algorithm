def dfs(depth, sum):
    global N, K, A, cnt
    if sum == K :
        cnt += 1
        return
    if depth == N :
        return
    dfs(depth+1, sum+A[depth])
    dfs(depth+1, sum)



T = int(input())

for t in range(1, T+1):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))[:N]
    cnt = 0
    dfs(0, 0)
    print(f"#{t} {cnt}")