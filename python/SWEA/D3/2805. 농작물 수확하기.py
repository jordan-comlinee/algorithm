T = int(input())

for t in range(1, T+1):
    N = int(input())
    farm = [list(input()) for _ in range(N)]
    sum = 0
    mid = N//2
    for i in range(N):
        sum += int(farm[i][mid])
        S = abs(mid-abs(i-mid))
        if S>=1 :
            for s in range(1, S+1):
                sum += int(farm[i][mid-s])+int(farm[i][mid+s])
    print(f"#{t} {sum}")
