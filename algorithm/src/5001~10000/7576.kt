package `5001~10000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.Queue
import java.util.StringTokenizer
private  var unrippedTomato = 0
private val dx = listOf(-1, 1, 0, 0)
private val dy = listOf(0, 0, -1, 1)
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    val M = st.nextToken().toInt()
    val N = st.nextToken().toInt()
    val board = Array(N){IntArray(M) }
    var queue = LinkedList<Pair<Int, Int>>()
    repeat(N) { x->
        val st2 = StringTokenizer(br.readLine())
        repeat(M) { y->
            board[x][y] = st2.nextToken().toInt()
            if (board[x][y] == 1) queue.add(Pair(x, y))
            else if (board[x][y] == 0) unrippedTomato++
        }
    }
    if (unrippedTomato == 0) {
        println(0)
        return
    }

    val result = bfs(board, queue)
    if (unrippedTomato > 0) println(-1)
    else println(result)

}
private fun bfs(board : Array<IntArray>, queue : Queue<Pair<Int, Int>>) : Int {
    var day = 0
    while (queue.isNotEmpty()) {
        val pair = queue.poll()
        val x = pair.first
        val y = pair.second
        day = board[x][y]
        for (i in 0 until 4) {
            val nx = x + dx[i]
            val ny = y + dy[i]
            if (nx !in board.indices || ny!in board[0].indices || board[nx][ny] != 0) continue
            unrippedTomato--
            board[nx][ny] = board[x][y] + 1
            queue.offer(Pair(nx, ny))
        }
    }
    return day-1
}