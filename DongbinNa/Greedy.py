# 거스름돈
def solution1(n):
    count = 0
    array = [500, 100, 50, 10]
    for coin in array:
        count += n // coin
        n %= coin
    return count

print("거스름돈 횟수:", solution1(1260))

# 1이 될 때까지 *****
def solution2(n, k):
    count = 0
    while True:
        target = (n//k) * k
        count += n-target
        if n<k:
            break
        count += 1
        n //= k
    return count

print(solution2(17, 4))

# 곱하기 혹은 더하기

def solution3(n):
    result = int(n[0])

    for i in range(1, len(n)):
        num = int(n[i])
        if num <= 1 or result <= 1 :
            result += num
        else:
            result *= num
    return result

print(solution3("02984"))

# 모험가 길드

def solution4():
