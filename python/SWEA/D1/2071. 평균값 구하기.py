t = int(input())

for i in range(1, t+1) :
    num_list = list(map(int, input().split()))
    sum = 0
    for j in range(10) :
        sum += num_list[j]
    print("#%d %d"%(i, round(sum/10, 0)))
