T = int(input())

for t in range(1, T+1) :
    N, M = map(int, input().split())
    n_list = list(map(int, input().split()))
    hap_list = [-1]
    for i in range(N-1):
        for j in range(i+1, N):
            if (n_list[i] + n_list[j] <= M ):
                hap_list.append(n_list[i] + n_list[j])
    print(f"#{t} {max(hap_list)}")