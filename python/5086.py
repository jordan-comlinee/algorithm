def main(a, b) :
    if (b%a==0):
        return "factor"
    elif (a%b==0) :
        return "multiple"
    else :
        return "neither"

while True :
    a, b = list(map(int, input().split()))
    if (a == 0 & b == 0) : break
    print(main(a, b))