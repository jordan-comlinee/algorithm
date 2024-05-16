def isPalindrome(N):
    if len(N) == 0 :
        return 0
    for i in range(len(N)//2):
        if (N[i] != N[len(N)-i-1]) :
            return 0
    return 1
for t in range(1, 11) :
    N = int(input())
    board = [list(input()) for _ in range(8)]
    cnt = 0
    for i in range(8):
        for j in range(8):
            word1, word2 = '', ''
            if (j <= 8-N) :
                word1 = board[i][j:j+N]
            if (i <= 8-N) :
                for k in range(N):
                    word2 += board[i+k][j]
            cnt += isPalindrome(word1) + isPalindrome(word2)
    print(f"#{t} {cnt}")