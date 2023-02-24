# 1st hit
# 중복된 배열을 제거하는 것이 아닌, 연속으로 나타나는 숫자를 하나만 남기고 제거하는 것.

def solution(arr):
    return list(dict.fromkeys(arr))


print(solution([1,1,3,3,0,1,1]))

# 2nd hit

def solution2(arr):
    answer = []
    for i in range(len(arr)-1):
        if arr[i] != arr[i+1]:
            answer.append(arr[i])
    return answer


print(solution2([1, 1, 3, 3, 0, 1, 1]))


# 3rd hit_런타임 오류

def solution3(arr):
    stack = []
    result = [arr[0]]
    for num in arr:
        if stack:
            curr = stack.pop()
            if curr != num:
                result.append(num)

        stack.append(num)
    return result

print(solution3([1, 1, 3, 3, 0, 1, 1]))