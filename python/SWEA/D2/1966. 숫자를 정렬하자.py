T = int(input())

for t in range(1, T+1):
    N = int(input())
    n_list = list(map(int, input().split()))[:N]
    n_list.sort()
    print(f"#{t}", end='')
    for n in n_list : print(f" {n}", end='')
    print()