'''
def max_profit(n, list) :
    profit= 0
    while(len(list)>0):
        for i in range(0, list.index(max(list))):
            profit += max(list) - list[i]
        list = list[list.index(max(list))+1:]
    print("#%d %d"%(n, profit))

t = int(input())

for i in range(1, t+1) :
    n = int(input())
    n_list = list(map(int, input().split()))
    max_profit(i, n_list)
'''
T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
# ///////////////////////////////////////////////////////////////////////////////////
    n=int(input())
    price=list(map(int,input().split()))

    result=0
    max_num=0
    for i in range(len(price)-1,-1,-1):

        if price[i]>max_num:
            max_num=price[i]
        else:
            result+=max_num-price[i]

    print('#%d %d'%(test_case,result))
# ///////////////////////////////////////////////////////////////////////////////////