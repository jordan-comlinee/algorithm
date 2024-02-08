def recursive_dfs(v, visited = []) :
    # 시작 정점 방문
    visited.append(v)
    for w in graph[v]:
        # 방문하지 않았을 때
        if w not in visited:
            visited = recursive_dfs(w, visited)
    return visited

def itertive_dfs(start_v) :
    visited = []
    stack = [start_v]
    while stack :
        v = stack.pop()
        if v not in visited :
            visited.append(v)
            for w in graph[v]:
                stack.append(w)
    return visited