total_price = int(input())
num = int(input())
price = int(0)
for i in range(0, num):
    amount, unit = map(int, input().split())
    price += (amount*unit)

if total_price == price :
    print("Yes")
else:
    print("No")
