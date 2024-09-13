package `5001~10000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.StringTokenizer

private var unrippedTomato = 0
private val dh = listOf(-1, 1, 0, 0, 0, 0)
private val dn = listOf(0, 0, -1, 1, 0, 0)
private val dm = listOf(0, 0, 0, 0, -1, 1)
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (M, N, H) = br.readLine().split(" ").map { it.toInt() }
    val board = Array(H) {Array(N){ IntArray(M) } }
    val queue = LinkedList<List<Int>>()
    repeat(H) { h ->
        repeat(N) { n ->
            val st = StringTokenizer(br.readLine())
            repeat(M) { m ->
                board[h][n][m] = st.nextToken().toInt()
                if (board[h][n][m] == 0) unrippedTomato++
                if (board[h][n][m] == 1) queue.add(listOf(h, n, m))
            }
        }
    }

    if (unrippedTomato == 0) {
        println(0)
        return
    }
    val result = bfs(board, queue)
    if (unrippedTomato > 0) {
        println(-1)
        return
    }
    println(result)
}

private fun bfs(board : Array<Array<IntArray>>, queue : LinkedList<List<Int>>) : Int {
    var day = 0
    while (queue.isNotEmpty()) {
        val (h, n, m) = queue.poll()
        day = board[h][n][m]
        for (i in 0 until 6) {
            val nh = h + dh[i]
            val nn = n + dn[i]
            val nm = m + dm[i]
            if (nh !in board.indices || nn !in board[0].indices
                || nm !in board[0][0].indices || board[nh][nn][nm] != 0) continue
            unrippedTomato--
            board[nh][nn][nm] = board[h][n][m]+1
            queue.offer(listOf(nh, nn, nm))
        }
    }
    return day-1
}