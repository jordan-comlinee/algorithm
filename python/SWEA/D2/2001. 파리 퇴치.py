t = int(input())

def check_fly(fly_list, i, j, m) :
    sum = 0
    for x in range(m):
        for y in range(m):
            sum += fly_list[i+x][j+y]
    return sum

for _ in range(1, t+1) :
    n, m = map(int, input().split())
    fly_list = [list(map(int, input().split())) for _ in range(n)]
    ans_list = [[0 for _ in range(n-m+1)] for _ in range(n-m+1)]
    for i in range(n-m+1):
        for j in range(n-m+1):
            ans_list[i][j] = check_fly(fly_list, i, j, m)
    print(f"#{_} {max(map(max, ans_list))}")