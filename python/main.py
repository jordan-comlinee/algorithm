a = [[1,2,3,4,5], [6,4,2,1,8], [3,5,2,4,6], [9,8,7,6,5], [9, 9, 1, 1, 1]]

a.sort(key= lambda x: (x[1], x[0]), reverse=True)
print(a)