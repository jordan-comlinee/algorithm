import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.Queue
import java.util.StringTokenizer

private var dx = 0
private var dy = 0
private lateinit var board: Array<IntArray>
private lateinit var result: Array<IntArray>

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = br.readLine().split(" ").map { it.toInt() }
    board = Array(n) { IntArray(m) }
    result = Array(n) { IntArray(m) { -1 } } // 최단 거리 결과 배열, 초기값 -1

    // 보드 초기화 및 목표 위치 (dx, dy) 찾기
    repeat(n) { i ->
        val st = StringTokenizer(br.readLine())
        repeat(m) { j ->
            board[i][j] = st.nextToken().toInt()
            if (board[i][j] == 2) {
                dx = i
                dy = j
            }
        }
    }

    // BFS 실행하여 각 지점의 최단 거리 계산
    bfs(n, m)

    // 결과 출력
    result.forEach { row ->
        println(row.joinToString(" "))
    }
}

private fun bfs(n: Int, m: Int) {
    val queue: Queue<Pair<Int, Int>> = LinkedList()
    val directions = arrayOf(
        Pair(-1, 0), Pair(1, 0), Pair(0, -1), Pair(0, 1)
    ) // 상, 하, 좌, 우 방향 벡터

    // 시작 위치 (목표 지점)을 큐에 넣고, 시작 지점의 거리는 0
    queue.offer(Pair(dx, dy))
    result[dx][dy] = 0

    while (queue.isNotEmpty()) {
        val (x, y) = queue.poll()

        // 4방향 탐색
        for (dir in directions) {
            val nx = x + dir.first
            val ny = y + dir.second

            // 배열 범위 체크 및 방문하지 않은 지점만 처리
            if (nx in 0 until n && ny in 0 until m && board[nx][ny] == 1 && result[nx][ny] == -1) {
                result[nx][ny] = result[x][y] + 1
                queue.offer(Pair(nx, ny))
            }
        }
    }

    // 도달 불가능한 곳(즉, 1인데도 불구하고 방문되지 않은 곳)은 -1로 유지
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (board[i][j] == 1 && result[i][j] == -1) {
                result[i][j] = -1
            } else if (board[i][j] == 0) {
                result[i][j] = 0 // 장애물인 곳은 0으로 표시
            }
        }
    }
}
