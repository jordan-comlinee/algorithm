def pyramid1(n):
    m = n * 2 + 1
    for i in range(1, m, 2):
        for j in range((m - i) // 2 - 1):
            print(" ", end="")
        for j in range(i):
            print("*", end="")
        print("")

def pyramid2(n):
    output = ""
    n += 1
    for i in range(1, n):
        for j in range(n - 1, i, -1):
            output += ' '
        for j in range(0, 2 * i - 1):
            output += '*'
        output += '\n'
    print(output)

print("두개 피라미드의 층 수를 각각 입력하세요.")
n1, n2 = map(int, input().split())

pyramid1(n1)
print("\n")
pyramid2(n2)
