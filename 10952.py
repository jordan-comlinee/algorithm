import sys

while(1):
    a, b = map(int, sys.stdin.readline().split())
    if(a == b == 0):
        break
    sys.stdout.write("%s\n" % (a+b))
