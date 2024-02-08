# 학생의 수를 구하기 위한 n 입력
n = int(input())
m = [[0] * n for _ in range(n)]
# 학생을 배치할 순서
studentList = []
# 학생이 좋아하는 학생들 리스트
studentLikeList = []
# 총점수
totalScore = 0
for i in range(n**2):
    student = list(map(int, input().split()))
    if len(student) !=5:
        break
    studentList.append(student[0])
    studentLikeList.append(student[1:5])
# 상, 하, 좌, 우
dx, dy = (0, -1, 0, 1),(-1, 0, 1, 0)
# 가야 할 자리 탐색 시작...교실의 위치 좌표, 그리고 넣을 학생 번호를 input으로 받고, 괜찮은 곳을 return받음
def bfs(ix, iy, num):
    score = 0
    for i in range(4):
        idx, idy = ix+dx[i], iy+dy[i]
        if idx<0 or idy<0 or idx>=n or idy>=n:
            continue
        elif m[idx][idy] in studentLikeList[num]:
            score +=10
        elif m[idx][idy] == 0:
            score +=1
        else:
            continue
    return score

def getScore(x, y):
    likeStudent = 0
    for i in range(4):
        idx, idy = x+dx[i], y+dy[i]
        if idx < 0 or idy < 0 or idx >= n or idy >= n:
            continue
        if m[idx][idy] in studentLikeList[studentList.index(m[x][y])]:
            likeStudent+=1
    return likeStudent

# 학생들 차례대로 위치 지정해줌, 동일한 점수를 가진 경우...구분
for i in range(len(studentList)):
    score = 0
    mx, my = 0, 0
    # 모든 교실 위치에 대해 어떤 곳이 더 좋은 장소인 지 탐색
    for ii in range(n):
        for jj in range(n):
            if m[ii][jj] == 0:
                if bfs(ii, jj, i) > score:
                    score = bfs(ii, jj, i)
                    mx, my = ii, jj
            else:
                continue
    m[mx][my] = studentList[i]
    print(m)
print(m)
for i in range(n):
    for j in range(n):
        studentLike = getScore(i, j)
        if studentLike == 0:
            totalScore +=0
        else:
            totalScore += 10**(studentLike-1)

print(totalScore)