package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

private lateinit var maze : Array<IntArray>
private val queue = LinkedList<Pair<Int, Int>>()
private var N = 0
private var M = 0
private val dx = arrayOf(-1, 1, 0, 0)
private val dy = arrayOf(0, 0, -1, 1)
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    M = st.nextToken().toInt()
    maze = Array(N){IntArray(M)}
    repeat(N) { n ->
        val i = br.readLine()
        repeat(M) { m ->
            maze[n][m] = i[m].toString().toInt()
        }
    }
    queue.add(Pair(0, 0))
    println(bfs())
}

private fun bfs() : Int {
    var result = 0
    var visited = Array(N){IntArray(M){1} }
    while (queue.isNotEmpty()) {
        val head = queue.poll()
        repeat(4) {
            val nx = head.first+dx[it]
            val ny = head.second+dy[it]
            if (nx in 0 until N && ny in 0 until M &&
                maze[nx][ny] == 1 && visited[nx][ny]==1) {
                queue.offer(Pair(nx, ny))
                visited[nx][ny] = visited[head.first][head.second]+1
                if (nx == N-1 && ny == M-1){
                    result = visited[nx][ny]
                    return result
                }
            }
        }
    }
    return result
}