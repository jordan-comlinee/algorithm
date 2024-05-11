T = int(input())

for t in range(1, T+1):
    N = int(input())
    print(f"#{t} {((N+1)//2)*pow(-1, (N+1))}")