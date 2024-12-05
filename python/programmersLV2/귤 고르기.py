def solution(k, tangerine):
    answer = 0
    m = [[0, i] for i in range(0, max(tangerine) + 1)]
    for i in range(len(tangerine)):
        m[tangerine[i]][0] += 1

    m.sort(reverse=True)
    for i in range(len(m)):
        k -= m[i][0]
        answer += 1
        if (k <= 0):
            return answer

    return answer