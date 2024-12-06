def solution(numbers):
    answer = ''
    num_str_list = [list(str(n)) for n in numbers]
    num_str_list.sort(key=lambda x: (x * 3), reverse=True)

    for i in num_str_list:
        answer += ''.join(i)

    return str(int(answer))