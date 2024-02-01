# board : 각 칸에 색깔 이름이 담긴 이차원 문자열 리스트
# h : 고른 칸의 위치 , 정수
# w : 고른 칸의 위치, 정수
def solution(board, h, w):
    answer = 0
    color = board[h][w]
    # 보드의 위, 아래, 왼쪽, 오른쪽을 검사하기 위한 좌표 이동
    dx , dy = [1, -1, 0, 0], [0, 0, 1, -1]

    for i in range(0, 4) :
        if( len(board) > dx[i]+h >= 0 and len(board[0]) > dy[i]+w >= 0) :
            if(board[h+dx[i]][w+dy[i]] == color) :
                answer +=1
    return answer




board = [["blue", "red", "orange", "red"], ["red", "red", "blue", "orange"], ["blue", "orange", "red", "red"], ["orange", "orange", "red", "blue"]]
h = 1
w = 1
print(solution(board, h, w))