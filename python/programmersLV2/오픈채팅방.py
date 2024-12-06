def set_text(text) :
    enter_text = "님이 들어왔습니다."
    exit_text = "님이 나갔습니다."
    if (text == "Enter") :
        return enter_text
    else :
        return exit_text

def solution(record):
    record_list = [i.split(" ") for i in record]
    text_list = []
    answer = []
    uid_list = {}
    for i in range(len(record_list)):
        if not record_list[i][0] == 'Leave' :
            uid_list[record_list[i][1]] = record_list[i][2]
        if not record_list[i][0] == 'Change' :
            text_list.append([record_list[i][1], set_text(record_list[i][0])])
    for i in range(len(text_list)) :
        answer.append(uid_list[text_list[i][0]] + text_list[i][1])
    return answer