# 1st hit

def solution(n):
    answer = ''
    for i in range(n):
        if i % 2 == 0:
            answer += "수"
        else:
            answer += "박"
    return answer

print(solution(3))

# 2nd hit

def solution2(n):
    return "수박" * (n//2) + "수" * (n%2)

print(solution2(5))