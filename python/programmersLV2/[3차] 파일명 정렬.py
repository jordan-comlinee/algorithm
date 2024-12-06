def solution(files):
    answer = [[_] for _ in files]
    result = []
    for a in range(len(answer)) :
        strLen = len(answer[a][0])
        numberIndex = strLen
        tailIndex = strLen
        for i in range(strLen):
            if answer[a][0][i].isdigit() == True :
                numberIndex = i
                break
        for i in range(numberIndex, strLen):
            if answer[a][0][i].isdigit() == False:
                tailIndex = i
                break
        answer[a].append(answer[a][0][:numberIndex].lower())
        answer[a].append(int(answer[a][0][numberIndex:tailIndex]))
    answer.sort(key =lambda x: (x[1], x[2]) )
    for a in answer :
        result.append(a[0])
    return result