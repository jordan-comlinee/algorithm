def othello(x, y, color):
    global board, N
    # 세로선, 대각선 리스트
    h_board, c_board = list(), list()
    # 자신이 놓을 돌과 자신의 돌 사이에 상대편의 돌이 있는 지 확인


    board[x][y] = color

T = int(input())

for t in range(1, T+1) :
    # N = 보드의 한 변의 길이, M = 플레이어가 돌을 놓는 횟수
    N, M = map(int, input().split())
    board = [[0]*N for _ in range(N)]
    board[N//2][N//2], board[(N//2)-1][(N//2)-1] = 2, 2
    board[(N//2)-1][N//2], board[N//2][(N//2)-1] = 1, 1
    for m in range(M) :
        x, y, color = map(int, input().split())
        othello(x-1, y-1, color)

    for _ in range(N) :
        print(board[_])