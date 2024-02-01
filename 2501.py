def main(n, k):
    t_list = []
    if(k == 0 or k > n) :
        return
    for t in range(1, n+1):
        if (n%t == 0):
            t_list.append(t)
    if (len(t_list) < k) :
        return 0
    return t_list[k-1]

n, k = list(map(int, input().split()))
print(main(n, k))