# 피보나치 수열 만들기 -- 중복되는 부분이 많다는 문제가 있음
'''
def fibo(x):
    if x == 1 or x == 2:
        return 1
    return fibo(x-1) + fibo(x-2)

print(fibo(4))
'''

# 메모이제이션을 이용한 구현
'''
d = [0] * 100

def fibo(x):
    if x == 1 or x == 2:
        return 1
    if d[x] != 0:
        return d[x]

    d[x] = fibo(x-1) + fibo(x-2)
    return d[x]
print(fibo(99))
'''

d = [0] * 100

d[1]=1
d[2]=1
n=99
for i in range(3, n+1):
    d[i] = d[i-1] + d[i-2]

print(d[n])

# 개미 전사 답안 예시
'''
# 정수 n 입력받기
n = int(input())
# 모든 식량 정보 입력 받기
array = list(map(int,  input().split()))
# DP 테이블 초기화
d = [0] * 100
# 다이나믹 프로그래밍 진행
d = array[0]
d[1] = max(array[0], array[1])
for i in range(2, n):
    d[i] = max(d[i-1], d[i-2] + array[i])
# 결과
print(d[n-1])
'''
# 1로 만들기

x = int(input())

d = [0] * 30001

for i in range(2, x+1):
    d[i] = d[i-1] + 1
    if i % 2 == 0:
        d[i] = min(d[i], d[i // 2] + 1)
    if i % 3 == 0:
        d[i] = min(d[i], d[i // 3] + 1)
    if i % 5 == 0:
        d[i] = min(d[i], d[i // 5] + 1)

print(d[x])
