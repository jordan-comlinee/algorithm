package `20001~25000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.Queue
import java.util.StringTokenizer

private var N = 600
private var M = 600
private var campus = Array(N){ MutableList<String>(M) { "" } }
private var visited = Array(N){ MutableList<Boolean>(M) { false } }
private var cnt = 0
private val queue : Queue<Pair<Int, Int>> = LinkedList()
private val dx = listOf(-1, 1, 0, 0)
private val dy = listOf(0, 0, -1, 1)
private fun bfs() {
    while (queue.isNotEmpty()) {
        val current = queue.poll()
        val x = current.first
        val y = current.second
        for (i in 0 until 4) {
            val nx = x + dx[i]
            val ny = y + dy[i]
            if (nx in 0 until N && ny in 0 until M  && campus[nx][ny] != "X" && !visited[nx][ny]) {
                if (campus[nx][ny] == "P") {
                    cnt += 1
                }
                visited[nx][ny] = true
                queue.offer(Pair(nx, ny))
            }
        }
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    M = st.nextToken().toInt()
    repeat(N) { n ->
        val line = br.readLine().toCharArray().map { it.toString() }
        campus[n] = line.toMutableList()
        repeat(M) { m ->
            if (campus[n][m] == "I") {
                queue.offer(Pair(n, m))
            }
        }
    }
    bfs()
    if (cnt == 0) {
        println("TT")
        return
    }
    println("$cnt")
}