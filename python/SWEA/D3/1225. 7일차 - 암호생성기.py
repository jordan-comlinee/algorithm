for t in range(10):
    T = int(input())
    pw_list = list(map(int, input().split()))
    while(0 not in pw_list) :
        for i in range(1, 6):
            if (pw_list[0]-i > 0):
                tmp = pw_list[0] - i
                pw_list = pw_list[1:]
                pw_list.append(tmp)
            else :
                tmp = 0
                pw_list = pw_list[1:]
                pw_list.append(tmp)
                break


    print(f"#{T}", end="")
    for i in pw_list:
        print(f" {i}", end="")
    print("")