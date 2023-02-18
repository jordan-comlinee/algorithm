# 1st hit
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