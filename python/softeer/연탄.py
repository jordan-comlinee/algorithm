# n : 집의 수
# radius : 각 집에 놓여있는 난로의 반지름의 길이
def main(n, radius_list) :
    answer = 0
    count = 0
    radius_list = radius_list[0:n]
    max_radius = max(radius_list)
    for num in range(2, max_radius+1) :
        for radius in radius_list :
            if(radius % num == 0) :
                count+= 1
        if (count > answer) :
            answer = count
        count = 0
    return answer

n = int(input())
radius_list = list(map(int, input().split()))
print(main(n, radius_list))
