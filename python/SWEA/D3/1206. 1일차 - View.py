for t in range(1, 11) :
    N = int(input())
    result = 0
    buildings = list(map(int, input().split()))[:N]
    for i in range(2, N-2) :
        near = max(buildings[i-2], buildings[i-1],buildings[i+1], buildings[i+2])
        if(near < buildings[i]):
            result += buildings[i] - near
    print(f"#{t} {result}")
