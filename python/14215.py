def main(a, b, c) :
    list_triangle = [a,b,c]
    list_triangle.sort()
    if(list_triangle[0] + list_triangle[1] > list_triangle[2]) :
        return sum(list_triangle)
    else :
        return (list_triangle[0]+list_triangle[1])*2-1

a, b, c = list(map(int, input().split()))
print(main(a, b, c))