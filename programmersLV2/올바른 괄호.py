# 1st hit

def solution(s):
    while s.find("()") != -1 :
        s = s.replace("()","")
    if (len(s) != 0) :
        return False
    return True


print(solution("()(())("))


# 2nd hit

def solution2(s):
    stack = []
    for c in s:
        if c == "(":
            stack.append(c)
        else:
            if stack:
                stack.pop()
            else:
                return False
    if stack:
        return False
    return True

print(solution2("()(())("))