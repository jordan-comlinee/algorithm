package `10001~15000`

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.abs

private var N = 0
private lateinit var painting : Array<CharArray>
private lateinit var visited : Array<BooleanArray>
private var moving = arrayOf(Pair(1, 0), Pair(-1, 0), Pair(0, 1), Pair(0, -1))
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var result = 0
    var result2 = 0
    N = br.readLine().toInt()
    painting = Array(N) {CharArray(N)}
    for (i in 0 until N) {
        painting[i] = br.readLine().toCharArray()
    }
    visited = Array(N) {BooleanArray(N) {false} }
    repeat(N) { i ->
        repeat(N) { j ->
            if (!visited[i][j]) {
                result += 1
                bfs(i, j)
            }
        }
    }
    visited = Array(N) {BooleanArray(N) {false} }
    repeat(N) { i ->
        repeat(N) { j ->
            if (!visited[i][j]) {
                result2 += 1
                bfs_c(i, j)
            }
        }
    }
    print("${result} ${result2}")
}

private fun bfs(x : Int, y : Int) {
    visited[x][y] = true
    for (m in moving) {
        val nx = x + m.first
        val ny = y + m.second
        if (nx in visited.indices && ny in visited.indices && !visited[nx][ny]) {
            if (painting[x][y] == painting[nx][ny]) {
                bfs(nx, ny)
            }
        }
    }
    return
}

private fun bfs_c(x : Int, y : Int) {
    visited[x][y] = true
    for (m in moving) {
        val nx = x + m.first
        val ny = y + m.second
        if (nx in visited.indices && ny in visited.indices && !visited[nx][ny]) {
            if (painting[x][y] == painting[nx][ny] || abs(painting[x][y]- painting[nx][ny]) == 11) {
                bfs_c(nx, ny)
            }
        }
    }
    return
}