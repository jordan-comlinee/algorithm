T = int(input())

for t in range(1, T+1) :
    N = int(input())
    print(f"#{t}")
    pascal = [[1]for _ in range(N)]
    print(pascal[0][0])
    for i in range(1, N):
        for j in range(1, i):
            pascal[i].append(pascal[i-1][j-1]+pascal[i-1][j])
        pascal[i].append(1)
        for n in pascal[i]:
            print(n, end=' ')
        print()
