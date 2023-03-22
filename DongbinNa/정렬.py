
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

# 선택정렬
'''
for i in range(len(array)):
    # 가장 작은 원소의 인덱스
    min_index = i
    for j in range(i+1, len(array)):
        if array[min_index] > array[j]:
            min_index = j
    # 스와프
    array[i], array[min_index] = array[min_index], array[i]

print(array)
'''
# 삽입정렬
'''
for i in range(1, len(array)):
    # 인덱스 i부터 1까지 1씩 감소하며 반복하는 문법
    for j in range(i, 0, -1):
        # 한 칸씩 왼쪽으로 이동
        if array[j] < array[j-1]:
            array[j], array[j-1] = array[j-1], array[j]
        else:
            # 자기보다 작은 데이터를 만나면 그 위치에서 멈춤
            break
print(array)
'''
# 퀵 정렬
'''
def quick_sort(array, start, end):
    # 원소가 1개인 경우 종료
    if start >= end:
        return
    # 피벗은 첫번째 원소
    pivot = start
    left = start+1
    right = end
    while(left <= right):
        # 피벗보다 큰 데이터를 찾을 때까지 반복
        while(left<= end and array[left] <= array[pivot]):
            left += 1
        # 피벗보다 작은 데이터를 찾을 때까지 반복
        while(right > start and array[right] > array[pivot]):
            right -= 1
        # 엇갈렸다면 작은 데이터와 피벗을 교체
        if(left > right):
            array[right], array[pivot] = array[pivot], array[right]
        # 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
        else:
            array[left], array[right] = array[right], array[left]
    # 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
    quick_sort(array, start, right-1)
    quick_sort(array, right+1, end)

quick_sort(array, 0, len(array)-1)
print(array)
'''
# 계수 정렬
array2 = [7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2]

count = [0] * (max(array2)+1)

for i in range(len(array2)):
    count[array2[i]] += 1
for i in range(len(count)):
    for j in range(count[i]):
        print(i, end=' ')

