def solution(friends, gifts):
    gift_chart = [[0 for _ in range(len(friends))] for _ in range(len(friends))]
    gift_score = [0 for _ in range(len(friends))]
    get_score = [0 for _ in range(len(friends))]
    for gift in gifts :
        give = gift.split()[0]
        take = gift.split()[1]
        gift_chart[friends.index(give)][friends.index(take)] += 1
        gift_score[friends.index(give)] += 1
        gift_score[friends.index(take)] -= 1

    # gift_chart에서 각각의 점수를 비교함
    for i in range(0, len(friends)) :
        for j in range(0, i) :
            if(gift_chart[i][j] > gift_chart[j][i]) :
                get_score[i] += 1
            elif(gift_chart[j][i] > gift_chart[i][j]) :
                get_score[j] += 1
            else :
                if (gift_score[i] > gift_score[j]) :
                    get_score[i] += 1
                elif(gift_score[i] < gift_score[j]) :
                    get_score[j] += 1

    return max(get_score)

friends = ["joy", "brad", "alessandro", "conan", "david"]
gifts = ["alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"]

# print(gifts[0].split()[1])
print(solution(friends, gifts))