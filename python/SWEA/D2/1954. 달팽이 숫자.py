def fill_snail(snail):
    fill_list = list(range(1, len(snail)+1))
    fill_list.extend(range(1, len(snail)))
    fill_list.sort(reverse=True)
    move_list = [[1, 0], [0, -1], [-1, 0], [0, 1]]
    while(len(fill_list) > 0) :
        dx, dy = 0
    #for i in range(len(snail)):

    return snail

t = int(input())

for _ in range(1, t+1):
    n = int(input())
    snail = [[0]*n]*n
    snail = fill_snail(snail)
    print(f"#{_}")