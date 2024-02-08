# 1st hit
from collections import deque

def solution(progresses, speeds):
    progresses = deque()
    speeds = deque()
    release = 0
    answer = []
    while True:
        if len(progresses) == 0:
            break
        for i in range(0, len(progresses)):
            progresses[i] += speeds[i]
        while True:
            if progresses[0] >= 100:
                progresses[0].popleft()
                speeds[0].popleft()
                release +=1
            else:
                answer.append(release)
                release = 0
                break

    return answer

print(solution([93, 30, 55], [1, 30, 5]))