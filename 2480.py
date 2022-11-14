a, b, c = map(int, input().split())

reward = int(0)

if(a == b == c) :
    reward = 10000 + a * 1000
    print(reward)
elif(a == b or a == c):
    reward = 1000 + a * 100
    print(reward)
elif(b == c):
    reward = 1000 + b * 100
    print(reward)
else:
    reward = max(a, b, c) * 100
    print(reward)