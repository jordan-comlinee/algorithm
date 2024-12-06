def solution(m, n, board):
    answer = 0
    board = [list(x) for x in board]
    while True:
        isAllRemoved = True
        removed = [[False for _ in range(n)] for _ in range(m)]
        for i in range(0, m - 1):
            for j in range(0, n - 1):
                if (board[i][j] != "X" and board[i][j] == board[i][j + 1] == board[i + 1][j] == board[i + 1][j + 1]):
                    removed[i][j] = True
                    removed[i][j + 1] = True
                    removed[i + 1][j] = True
                    removed[i + 1][j + 1] = True

        for i in range(m):
            for j in range(n):
                if (removed[i][j]):
                    isAllRemoved = False
                    answer += 1
                    board[i][j] = "X"

            print(f"{removed[i]}")
        if (isAllRemoved):
            break

        while True:
            moved = 0
            for i in range(m - 1):
                for j in range(n):
                    if (board[i][j] != "X" and board[i + 1][j] == "X"):
                        board[i + 1][j] = board[i][j]
                        board[i][j] = "X"
                        moved = 1
            if (moved == 0):
                break

    return answer

solution(6, 6, ["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"])