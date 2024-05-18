def getLocation(n) :
    # 좌표의 층 수, 층의 점 최대값
    layer, lMax = 1, 0
    while (True) :
        lMax += layer
        if (lMax >= n):
            break
        layer+=1
    return layer-(lMax-n), 1+(lMax-n)
def star(p, q) :
    px, py = getLocation(p)
    qx, qy = getLocation(q)
    rx = px+ qx
    ry = py + qy
    rLayer = rx + ry -1
    rMax = 0
    for i in range(rLayer+1) : rMax += i
    return rMax-ry+1

T = int(input())

for t in range(1, T+1):
    p, q = map(int, input().split())
    result = star(p, q)
    print(F"#{t} {result}")