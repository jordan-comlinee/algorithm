n = int(input())
_list = ['3', '6', '9']
for i in range(1, n+1) :
    num = str(i)
    cnt = 0
    for j in range(0, len(num)):
        if (num[j] in _list):
            #print(f'{num}:{num[j]}', end=' ')
            cnt+=1

    if (cnt != 0):
        num = '-'*cnt

    print(num, end=' ')
