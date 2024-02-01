def main(N, M) :
    arr = list(map(int, input().split()))
    max_sum = 0
    for i in range(N) :
        for j in range(i+1, N):
            for k in range(j+1, N):
                if (arr[i]+arr[j]+arr[k] > M) :
                    continue
                else :
                    max_sum = max(max_sum, arr[i]+arr[j]+arr[k])
    return max_sum

N, M = map(int, input().split())
print(main(N, M))