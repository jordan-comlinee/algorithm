# 1st hit
def solution(absolutes, signs):
    answer = 0
    for i in range(len(absolutes)):
        answer += (absolutes[i] * (-1 if signs[i] == False else 1) )
    return answer

print(solution([4, 7, 12], [True,False,True]))
print(solution([1, 2, 3], [False,False,True]))