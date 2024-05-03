n = int(input())
n_list = list(map(int, input().split()))
n_list = n_list[:n]
n_list.sort()

print(n_list[n//2])