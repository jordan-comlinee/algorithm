# 1st hit

def solution(phone_number):
    if len(phone_number) < 4 or len(phone_number) > 20:
        return "Failed"
    answer = ("*"*(len(phone_number)-4)) + phone_number[len(phone_number)-4 :]
    return answer


print(solution('12345678'))