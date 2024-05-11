T = int(input())

for t in range(1, T+1):
    N, M = map(int, input().split())
    Aj = list(map(int, input().split()))[:N]
    Bj = list(map(int, input().split()))[:M]
    max = 0
    for i in range(abs(N-M)+1):
        sum = 0
        if N < M :
            for j in range(N):
                sum += Aj[j]*Bj[j+i]
            if sum > max :
                max = sum
        else :
            for j in range(M):
                sum += Bj[j]*Aj[j+i]
            if sum > max :
                max = sum
    print(f"#{t} {max}")
