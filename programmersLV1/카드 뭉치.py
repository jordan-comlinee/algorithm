# 1st hit
'''
def solution(cards1, cards2, goal):
    for i in range(0, len(goal), 1):
        if goal[i] == cards1[0]:
            cards1.remove(goal[i])
        elif goal[i] == cards2[0]:
            cards2.remove(goal[i])
        else:
            answer = 'No'
            break
        answer = 'Yes'
    return answer


a = solution(["I", "drink", "water"], ["like", "to"], ["I", "want", "to", "drink", "water"])
print(a)
'''

# 2nd hit
from collections import deque

def solution(cards1, cards2, goal):
    answer = ''
    q = deque(goal)
    q1 = deque(cards1)
    q2 = deque(cards2)
    b, c = q1.popleft(), q2.popleft()
    while q:
        a = q.popleft()
        if a == b:
            if len(q1) > 0:
                b = q1.popleft()
        elif a == c:
            if len(q2) > 0:
                c = q2.popleft()
        else:
            answer = "No"
            return answer
    answer = "Yes"
    return answer

a = solution(["I", "drink", "water"], ["want", "to"], ["I", "want", "to", "drink", "water"])
print(a)