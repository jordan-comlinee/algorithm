dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
start_point = []
end_point = []
lever_point = []
reachable = False
def get_points(maps):
    global start_point, lever_point, end_point
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if maps[i][j] == 'S':
                start_point = [i, j]
            elif maps[i][j] == 'L':
                lever_point = [i, j]
            elif maps[i][j] == 'E':
                end_point = [i, j]
    return

def dfs(start_point, end_point, depth, visited, maps) :
    if (start_point[0] == end_point[0] and start_point[1] == end_point[1]) :
        return
    for i in range(0, 4):
        nx = start_point[0] + dx[i]
        ny = start_point[1] + dy[i]
        if (nx >= 0 and nx < len(visited) and ny >= 0 and ny < len(visited[0]) and maps[nx][ny] != 'X'):
            visited[nx][ny] = True
            dfs([nx, ny], end_point, depth+1, visited, maps)
            visited[nx][ny] = False
    return

def solution(maps):
    answer = 0
    visited = [[False for _ in range(len(maps[0]))] for _ in range(len(maps))]
    get_points(maps)
    print(dfs(start_point, lever_point, answer, visited, maps))
    #if reachable :
    #    dfs(lever_point, end_point, answer, visited, maps)
    return answer

solution(["SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"])