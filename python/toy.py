def dfs(depth) :
    global result
    if depth == N :
        result += 1
        return
    for i in range(N) :
        board[depth] = i
        if check(depth):
            dfs(depth+1)
def check(n):
    for i in range(n):
        if(board[n] == board[i]) or (n-i == abs(board[n]-board[i])):
            return False
    return True



N = int(input())
board = [0]*N
result = 0
dfs(0)
print(f"{result}")