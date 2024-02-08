from collections import deque
# bandage = 기술의 시전 시간 t, 1초 당 회복량 x, 추가 회복량 y, 1차원 배열
# health = 최대 체력, 정수
# attacks = 몬스터의 공격 시간과 피해량, 2차원 배열
def solution(bandage, health, attacks):
    t = bandage[0]
    x = bandage[1]
    y = bandage[2]
    success_time = 1
    max_health = health
    attacks_deque = deque(attacks)
    for i in range(1, attacks[len(attacks)-1][0]+1) :
        # 몬스터에게 공격을 받은 경우, 플레이어의 체력이 감소하고 연속 성공 횟수가 초기화됨
        if (i == attacks_deque[0][0]) :
            health -= attacks_deque[0][1]
            attacks_deque.popleft()
            success_time = 1
        # 만약 기술 시전 시간이 되면, 1초 당 회복 체력+추가회복량 만큼 회복한다.
        elif (success_time == t) :
            health += (x+y)
            success_time = 1
        else :
            health += x
            success_time += 1
        if (health > max_health):
            health = max_health
        elif (health <= 0) :
            return -1

    return health

bandage = [4, 2, 7]
health = 20
attacks = [[1, 15], [5, 16], [8, 6]]

print(solution(bandage, health, attacks))