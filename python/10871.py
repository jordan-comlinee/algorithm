cnt, num  = map(int, input().split())

int_list = list(map(int, input().split()))

for i in range(0, cnt):
    if(int_list[i] < num) :
        print(int_list[i], end=" ")
