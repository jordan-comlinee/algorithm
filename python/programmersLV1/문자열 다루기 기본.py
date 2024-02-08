# 1st hit
def solution(s):
    answer = True
    if((len(s) == 4 or len(s) == 6) & s.isdigit() == True) :
        return answer
    else :
        answer = False
        return answer

print(solution("a234"))
print(solution("1234"))

# 2nd hit ... by others

def solution2(s):
    print(s.isdigit)
    return s.isdigit() and len(s) in [4, 6]

print(solution2("a234"))
print(solution2("1234"))