t = int(input())

for _ in range(1, t+1):
    num_list = list(map(int, input().split()))
    avg = round((sum(num_list)-max(num_list)-min(num_list))/8)
    print(f"#{_} {avg}")