import sys

#num = int(input())
num = int(sys.stdin.readline())
for i in range(0, num):
    #a, b = map(int, input().split())
    a, b = map(int, sys.stdin.readline().split())
    #print(a+b)
    sys.stdout.write("%s\n" % str(a+b))
