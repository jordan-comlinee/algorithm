T = int(input())
score_list = ['A+', 'A0', 'A-', 'B+', 'B0', 'B-', 'C+', 'C0', 'C-', 'D0']
for t in range(1, (T+1)):
    # 학생 수 N, 알고 싶은 학생의 번호 K
    N, K = map(int, input().split())
    K_score = 0
    student_list = [[0, _+1] for _ in range(N)]
    for i in range(N):
        mid, fin, ass = map(int, input().split())
        student_list[i][0] = mid*0.35 + fin*0.45 + ass*0.2
        if(student_list[i][1] == K):
            K_score = student_list[i][0]
    student_list.sort(reverse=True)
    # 백분율
    pscore = (student_list.index([K_score,K]))/N*10
    print(f"#{t} {score_list[int(pscore)]}")
