# 1st hit
def solution(seoul):
    answer = "김서방은 " + str(seoul.index("Kim")) + "에 있다"
    return answer

print(solution(["Jane", "Kim"]))

# 2nd hit ... by others
def solution2(seoul):
    answer = "김서방은 {}에 있다".format(seoul.index("Kim"))
    return answer

print(solution2(["Jane", "Kim"]))