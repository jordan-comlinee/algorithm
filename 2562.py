numbers = []
for i in range(9):
    numbers.append(int(input()))

maxi = 0
max = 0
for i in range(9) :
    if numbers[i] > max:
        max = numbers[i]
        maxi = i + 1
print(max, maxi)