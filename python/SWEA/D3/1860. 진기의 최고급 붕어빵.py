T = int(input())

for t in range(1, T+1) :
    N, M, K = map(int, input().split())
    n_list = list(map(int, input().split()))[:N]
    n_list.sort(reverse=True)
    fishcake, cooltime = 0, -1
    isPossible = "Possible"
    for i in range(0, max(n_list)+1) :
        cooltime += 1
        if cooltime == M :
            fishcake += K
            cooltime = 0
        while(i in n_list and isPossible == "Possible") :
            n_list.pop()
            if fishcake < 1 :
                isPossible = "Impossible"
            else :
                fishcake -= 1
    print(f"#{t} {isPossible}")