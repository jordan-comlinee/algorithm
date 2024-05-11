T = int(input())

for t in range(1, T+1):
    t1, t2, t3, t4 = map(int, input().split())
    H = t1+t3
    M = t2+t4
    if( M > 60 ) :
        H += 1
        M = M%60
    if( H > 12 ) :
        H = H - 12
    print(f"#{t} {H} {M}")
