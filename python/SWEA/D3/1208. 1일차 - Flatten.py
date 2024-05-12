for t in range(1, 11):
    dump = int(input())
    N = list(map(int, input().split()))
    for d in range(dump):
        N[N.index(max(N))] -= 1
        N[N.index(min(N))] += 1
    print(f"#{t} {max(N)-min(N)}")