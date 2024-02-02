# m : 친구 수
# n : 격자 수

def main() :
    n, m = map(int, input().split())
    farm = [[] for _ in range(n)]
    m_location = [[0, 0] for _ in range(m)]
    max_fruit = 0
    max_fruit_list = []
    for i in range(n):
        farm[i] = list(map(int, input().split()))
    for i in range(m):
        m_location[i] = list(map(int, input().split()))
        m_location[i][0], m_location[i][1] = m_location[i][0]-1, m_location[i][1]-1
    # 3초 동안 최대로 얻을 수 있는 열매 수확양의 총 합을 구해야 한다.
    # 열매 수확은 3초 동안 이루어진다.
    # DFS 호출
    for friend in range(m):
        x, y = m_location[friend]
        visited = [[False] * n for _ in range(n)]
        visited[x][y] = True
        #max_fruit += dfs(x, y, 3, visited, farm)
        print(dfs(x, y, 3, visited, farm))
    max_fruit_list.append(max_fruit)
    return max(max_fruit_list)


def dfs(x, y, time_left, visited, farm):
    fruit = 0
    # 이동할 수 있는 좌표를 다음과 같이 나타낸다
    dx, dy = [1, 0, 0, -1], [0, 1, -1, 0]
    # 기저 조건: 시간이 다 떨어지면 종료
    if time_left == 0:
        return fruit

    # 현재 위치의 열매를 수확하고 시간을 감소
    fruit += farm[x][y]

    # 이동할 수 있는 방향으로 이동
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        # 격자 범위를 벗어나면 무시
        if 0 <= nx < len(farm) and 0 <= ny < len(farm) and not visited[nx][ny]:
            visited[nx][ny] = True
            dfs(nx, ny, time_left - 1, visited, farm)
            visited[nx][ny] = False


main()