for t in range(1, 11):
    N = int(input())
    table = [list(map(int, input().split()))[:N] for _ in range(N)]
    cnt = 0
    for i in range(N) :
        pre = 0
        for j in range(N) :
            if(pre == 1 and table[j][i] == 2) :
                cnt += 1
            if(table[j][i] != 0) :
                pre = table[j][i]
    print(f"#{t} {cnt}")