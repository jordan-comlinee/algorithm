T = int(input())

money_list = [50000, 10000, 5000, 1000, 500, 100, 50, 10]
for t in range(1, T+1):
    count = ''
    N = int(input())
    for i in range(len(money_list)):
        count += str(N//money_list[i]) + ' '
        N = N%money_list[i]
    print(f"#{t}\n{count}")