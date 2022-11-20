import sys

num = int(sys.stdin.readline())

for i in range(1, num+1):
    a, b = map(int, sys.stdin.readline().split())
    sys.stdout.write("Case #%s: %s + %s = %s\n" % (i, a, b, a+b))
