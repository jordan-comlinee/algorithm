
result = []
explore = []
n = int(input())
a = list(map(int, input().split()))
visited = [0] * n
'''
def dfs(depth):
    if depth == n:
        result.append(sum(abs(explore[i]-explore[i+1]) for i in range(n-1)))
        return
    for i in range(n):
        if visited[i]:
            continue
        explore.append(a[i])
        visited[i] = 1
        dfs(depth+1)
        visited[i]=0
        explore.pop()

dfs(0)
print(max(result))
'''


def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr)//2]
    lesser_arr, equal_arr, greater_arr = [], [], []
    for num in arr:
        if num < pivot:
            lesser_arr.append(num)
        elif num > pivot:
            greater_arr.append(num)
        else:
            equal_arr.append(num)
    return quick_sort(lesser_arr) + equal_arr + quick_sort(greater_arr)

sorted_a = quick_sort(a)

if(len(sorted_a) % 2 == 0):
    for i in range(len(sorted_a)//2):
        result.append(sorted_a[i])
        result.append(sorted_a[len(sorted_a)-1-i])
    print(result)
else:
    result.append(sorted_a[len(sorted_a)//2])
    for i in range(len(sorted_a)//2):
        result.append(sorted_a[i])
        result.append(sorted_a[len(sorted_a)-1-i])

hap = 0
for i in range(len(result)-1):
    hap += abs(result[i+1]-result[i])
print(hap)