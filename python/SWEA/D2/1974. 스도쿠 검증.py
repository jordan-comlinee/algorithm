# 1번 함수는 가로로 맞는 지 확인
# 2번 함수는 세로로 맞는 지 확인
# 3번 함수는 격자로 맞는 지 확인

def check1(puzzle) :
    check_list = list(range(1, 10))
    my_list = []
    for i in range(9):
        for j in range(9):
            my_list.append(puzzle[i][j])
        my_list.sort()
        if (my_list != check_list) :
            return False
        else:
            my_list = []
    return True

def check2(puzzle) :
    check_list = list(range(1, 10))
    my_list = []
    for i in range(9):
        for j in range(9):
            my_list.append(puzzle[j][i])
        my_list.sort()
        if (my_list != check_list):
            return False
        else:
            my_list = []
    return True

def check3(puzzle) :
    check_list = list(range(1, 10))
    my_list = []
    for dx in range(0, 7, 3) :
        for dy in range(0, 7, 3) :
            for i in range(3):
                for j in range(3):
                    my_list.append(puzzle[dx+i][dy+j])
            my_list.sort()
            if (my_list != check_list):
                return False
            else:
                my_list = []
    return True


t = int(input())
for _ in range(1, t+1) :
    isSudoku = 0
    puzzle = [list(map(int, input().split())) for _ in range(9)]
    if (check1(puzzle) and check2(puzzle) and check3(puzzle)) :
        isSudoku = 1
    print(f"#{_} {isSudoku}")