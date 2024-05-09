T = int(input())

for t in range(1, T+1) :
    N = int(input())
    str = ''
    for _ in range(N):
        a, b = input().split()
        b = int(b)
        str = str + a*b
    print(f"#{t}")
    for i in range(0, len(str)//10+1):
        if (len(str)<(i+1)*10):
            print(str[i*10:len(str)])
        else:
            print(str[i*10:(i+1)*10])