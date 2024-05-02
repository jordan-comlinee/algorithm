t = int(input())

for i in range(1, t+1) :
    tc_num = int(input())
    num_list = list(map(int, input().split()))
    freq = [0]*101
    mode = 0
    for i in num_list:
        freq[i] += 1
        if freq[i] >= freq[mode]: mode = i
    print(f"#{tc_num} {mode}")