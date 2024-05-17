def dfs(n, sum) :
    global cnt
    if(sum == K) :
        cnt += 1
        return
    if n == N :
        return
    dfs(n+1, sum+n_list[n])
    dfs(n+1, sum)

T = int(input())

for t in range(1, T+1) :
    N, K = map(int, input().split())
    n_list = list(map(int, input().split()))[:N]
    cnt = 0
    dfs(0, 0)
    print(f"#{t} {cnt}")