'''
def switch(N) :
    n = list(str(N))
    result = []
    for i in range(len(n)):
        for j in range(i+1, len(n)):
            tmp = n[i]
            n[i] = n[j]
            n[j] = tmp
            result.append(int(''.join(n)))
    return result

T = int(input())

for t in range(1, T+1) :
    N, chance = map(int, input().split())
    result = [N]
    for i in range(chance):
        res = []
        for n in result:
            res.extend(switch(n))
        result = res
    print(f"#{t} {max(result)}")
'''
def dfs(n) :
    global answer
    if n==N:
        answer = max(answer, int("".join(map(str, lst))))
        return
    for i in range(L-1):
        for j in range(i+1, L):
            lst[i], lst[j] = lst[j], lst[i]

            chk = int("".join(map(str, lst)))
            if (n, chk) not in v:
                dfs(n+1)
                v.append((n, chk))
            lst[j], lst[i] = lst[i], lst[j]

T = int(input())

for tc in range(1, T+1) :
    st, t = map(str, input().split())
    N = int(t)
    lst, v = [], []
    L = len(st)
    answer = 0
    for i in st :
        lst.append(i)
    dfs(0)
    print(f"#{tc} {answer}")