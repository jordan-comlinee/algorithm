# 삽입정렬의 확장

def sort_shell(arr):
    arr_size = len(arr)
    gap = arr_size // 2
    while gap > 0 :
        for i in range(gap, arr_size):
            tmp = arr[i]
            j = i - gap
            while j >= 0 and arr[j] > tmp:
                arr[j + gap] = arr[j]
                j -= gap
            arr[j + gap] = tmp
        gap //= 2

    return arr

arr = [3, 5, 1, 2, 7, 12, 6, 8, 9, 10, 4]

print(sort_shell(arr))
