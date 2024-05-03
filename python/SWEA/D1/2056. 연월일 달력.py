t = int(input())
one_list = [1, 3, 5, 7, 8, 10, 12]
zero_list = [4, 6, 8, 11]
for i in range(1, t+1):
    date = input()
    if (len(date)==8) :
        if (int(date[4:6]) in one_list and 0<int(date[6:8])<=31) :
            print(f"#{i} {date[:4]}/{date[4:6]}/{date[6:8]}")
        elif (int(date[4:6]) in zero_list and 0<int(date[6:8])<=30) :
            print(f"#{i} {date[:4]}/{date[4:6]}/{date[6:8]}")
        elif (int(date[4:6])==2 and 0<int(date[6:8])<=28):
            print(f"#{i} {date[:4]}/{date[4:6]}/{date[6:8]}")
        else:
            print(f"#{i} -1")