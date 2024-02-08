# 1st hit
a, b = map(int, input().strip().split(' '))
for i in range(b) :
    for j in range(a) :
        print("*", end="")
    print("")

# 2nd hit
print("=============")
answer = ('*'*a + "\n")*b
print(answer)