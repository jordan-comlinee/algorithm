# 내 답안
a = int(input())
#key = a
num = 0
resultTen = a // 10
resultNum = a % 10
aLoop = resultNum * 10 + ((resultTen + resultNum) % 10)
while (1):
    num += 1
    resultTen = aLoop // 10
    resultNum = aLoop % 10
    aLoop = resultNum*10 + ((resultTen + resultNum) % 10)
    if(aLoop == a):
        break;
print(num)

# 모범 답안!!
'''
n = int(input())
key = n
cnt = 0

while True:
    cnt+=1
    sum = n//10 + n%10
    n = n%10*10 + sum%10
    if (n == key):
        break
print(cnt)
'''