import sys

num = int(sys.stdin.readline())

# range의 범위를 잘 파악해두자!
for i in range(1,num+1):
    a, b = map(int, sys.stdin.readline().split())
    print("Case #%s: %s" % (i, a+b) )
