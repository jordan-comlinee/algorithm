T = int(input())

for t in range(1, T+1):
    n_list = [2, 3, 5, 7, 11]
    result = [0 for _ in range(5)]
    N = int(input())
    for i in range(5):
        while(N%n_list[i] == 0):
            result[i] += 1
            N = N // n_list[i]
    print(f"#{t}", end= '')
    for i in result :
        print(f" {i}", end='')
    print()