# 두재의 점의 위치를 기록하면서 처리하는 알고리즘
# 특정한 합을 가지는 부분 연속 수열 찾기

# 시작점과 끝점이 첫번째 원소의 인덱스를 가리키도록 한다
# 현재 부분의 합이 M과 같다면 count한다.
# 현재 부분의 합이 M보다 작으면 end를 1 증가한다.
# 현재 부분의 합이 M보다 크면 start를 1 증가시킨다.
# 모든 경우를 확인할 때까지 2번부터 4번까지의 과정을 반복한다.

n, m = map(int, input().split())

data = list(map(int, input().split()))

count = 0
interval_sum = 0
end = 0

for start in range(n):
    while interval_sum < m and end < n:
        interval_sum += data[end]
        end+=1
    if interval_sum == m:
        count +=1
    interval_sum -= data[start]
print(count)