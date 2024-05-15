T = int(input())

for t in range(1, T+1) :
    N = list(input())
    pnum = '0'
    cnt = 0
    for n in N :
        if n != pnum :
            cnt += 1
            pnum = n
    print(f"#{t} {cnt}")