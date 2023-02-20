# 1st hit
'''
def solution(n):
    answer = 0
    n_list = list(str(n))
    for i in range(len(n_list)):
        answer += int(n_list[i])
    return answer
'''


#2nd hit ... by others
# map 함수란 두번째 인자로 들어온 반복 가능한 자료형(리스트나 튜플)을 첫번째 인자로 들어온 함수에 하나씩 집어넣어서 함수를 수핼하는 함수
def solution(n):
    answer = sum(map(int, str(n)))
    return answer


print(solution(123450))