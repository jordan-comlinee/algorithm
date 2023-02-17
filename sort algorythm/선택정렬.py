def sort_selection(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i+1, len(arr)):
            if arr[min_index] > arr[j]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

arr = [3, 5, 1, 2, 7, 12, 6, 8, 9, 10, 4]

print(sort_selection(arr))