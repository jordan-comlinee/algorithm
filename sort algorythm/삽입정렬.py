def sort_insertion(arr):
    for i in range(1, len(arr)):
        for j in range(i, 0, -1):
            if arr[j] < arr[j-1]:
                arr[j], arr[j-1] = arr[j-1], arr[j]
            else:
                break
    return arr

arr = [3, 5, 1, 2, 7, 12, 6, 8, 9, 10, 4]

print(sort_insertion(arr))