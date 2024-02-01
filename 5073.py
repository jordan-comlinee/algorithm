def main(a, b, c) :
    list_triangle = [a, b, c]
    list_triangle.sort()
    if(list_triangle[0]+list_triangle[1] <= list_triangle[2]):
        return "Invalid"
    if (a==b==c):
        return "Equilateral"
    elif (a!=b and a!=c and b!=c) :
        return "Scalene"
    else :
        return "Isosceles"

while True:
    a, b, c = list(map(int, input().split()))
    if(a == b == c == 0) :
        break
    print(main(a, b, c))