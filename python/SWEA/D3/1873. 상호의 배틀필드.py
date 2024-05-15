def getTank(gameMap, H, W) :
    tank_list = ['^', 'v', '<', '>']
    for h in range(H):
        for w in range(W) :
            if gameMap[h][w] in tank_list :
                return(h, w, tank_list.index(gameMap[h][w]))

def move(tX, tY, d):
    global gameMap
    move_list = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    tank_list = ['^', 'v', '<', '>']
    # 탱크의 방향 먼저 정해준다
    gameMap[tX][tY] = tank_list[d]
    # 만약 탱크가 가는 방향 앞에 장애물이 없다면 움직인다
    dX = tX + move_list[d][0]
    dY = tY + move_list[d][1]

    if(0<= dX <len(gameMap) and 0<= dY < len(gameMap[0]) and gameMap[dX][dY] == '.')  :
        gameMap[dX][dY] = tank_list[d]
        gameMap[tX][tY] = '.'
        return dX, dY, d
    return tX, tY, d



def shoot(tankX, tankY, tankD):
    global gameMap
    move_list = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    dx, dy = tankX + move_list[tankD][0], tankY + move_list[tankD][1]
    while (0<=dx<len(gameMap) and 0<=dy<len(gameMap[0])) :
        if gameMap[dx][dy] == '*' :
            gameMap[dx][dy] = '.'
            break
        if gameMap[dx][dy] == '#' :
            break
        dx += move_list[tankD][0]
        dy += move_list[tankD][1]


T = int(input())
for t in range(1, T+1) :
    H, W = map(int, input().split())
    gameMap = [list(input())[:W] for _ in range(H)]
    # 탱크의 위치 확보
    tankX, tankY, tankD = getTank(gameMap, H, W)
    N = int(input())
    n_list = list(input())[:N]
    direction_list = ['U', 'D', 'L', 'R']
    for n in n_list :
        if n == 'S':
            shoot(tankX, tankY, tankD)
        elif n in direction_list :
            tankX, tankY, tankD = move(tankX, tankY, direction_list.index(n))
    print(f"#{t} ",end='')
    for i in range(H):
        print("".join(gameMap[i]))