def dfs(depth) :
    global result
    # 끝까지 도달하면 카운트 1 추가
    if depth == N :
        result += 1
        return
    # N층에 대해 dfs 수행 (백트래킹)
    for i in range(N) :
        # 만약 방문하지 않은 부분이라면
        if visited[i] == False :
            # i번째 위치에 방문 수행
            board[depth] = i
            # 다음 자리에 퀸을 놓을 수 있다면
            if check(depth) :
                # 방문 = true로 두고, 그 다음 층 dfs 수행,
                visited[i] = True
                dfs(depth+1)
                visited[i] = False

# 각 자리에 퀸을 놓을 수 있는 지 없는 지 확인함
def check(n):
    for i in range(n):
        if(board[n] == board[i]) or (n-i == abs(board[n]-board[i])):
            return False
    return True

T = int(input())

for t in range(1, T+1):
    N = int(input())
    board = [0]*N
    visited = [False]*N
    result = 0
    print(f"#{t} {result}")