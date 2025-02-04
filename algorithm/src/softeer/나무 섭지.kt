package softeer

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.StringTokenizer

private var dx = listOf(-1, 1, 0, 0)
private var dy = listOf(0, 0, -1, 1)
private var N = 0;
private var M = 0;
private lateinit var br : BufferedReader
private lateinit var st : StringTokenizer
private val board = mutableListOf<String>()
private val ghost = mutableListOf<Pair<Int, Int>>()
private val ghost_q = LinkedList<Pair<Int, Int>>()
private lateinit var namwoo : Pair<Int, Int>
private lateinit var exit : Pair<Int, Int>
private var escapable = false

private fun input_data() {
    br = BufferedReader(InputStreamReader(System.`in`))
    st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    M = st.nextToken().toInt()
    repeat(N) {
        val line = br.readLine()
        board.add(line)
        for (i in 0 until M) {
            if (board[it][i] == 'G') ghost.add(Pair(it, i))
            else if (board[it][i] == 'N') namwoo = Pair(it, i)
            else if (board[it][i] == 'D') exit = Pair(it, i)
        }
    }
}
private fun ghost_move(ghostVisied :Array<BooleanArray>) {
    val size = ghost_q.size
    repeat(size) {
        val gx = ghost_q.peek().first
        val gy = ghost_q.peek().second
        ghost_q.poll()
        for (i in 0 until 4) {
            val nx = gx + dx[i]
            val ny = gy + dy[i]
            if (nx in board.indices && ny in board[0].indices && !ghostVisied[nx][ny]) {
                ghostVisied[nx][ny] = true;
                ghost_q.offer(Pair(nx, ny))
            }
        }
    }
}
private fun solution() {
    val visited = Array(N) {BooleanArray(M) {false} }
    val ghostvisited = Array(N) {BooleanArray(M) {false} }
    val q = LinkedList<Pair<Int, Int>>()

    q.offer(namwoo)
    for (i in ghost) {
        ghost_q.offer(i)
        ghostvisited[i.first][i.second] = true
    }
    visited[namwoo.first][namwoo.second] = true
    while (!q.isEmpty()) {

        val size = q.size
        repeat(size) {
            val current_namwoo = q.peek()
            q.poll()
            if (current_namwoo.first == exit.first && current_namwoo.second == exit.second) {
                //println("yessss")
                escapable = true
                return
            }
            for (i in 0 until 4) {
                val nx = current_namwoo.first + dx[i]
                val ny = current_namwoo.second + dy[i]
                if (nx in board.indices && ny in board[0].indices && board[nx][ny] != '#' && !visited[nx][ny] && !ghostvisited[nx][ny]) {
                    q.offer(Pair(nx, ny))
                    visited[nx][ny] = true
                }
            }
        }
        ghost_move(ghostvisited)
        /*
        for (i in 0 until N) {
            for (j in 0 until M) {
                print("${visited[i][j]} ")
            }
            println()
        }
        println("----------------------")
        for (i in 0 until N) {
            for (j in 0 until M) {
                print("${ghostvisited[i][j]} ")
            }
            println()
        }
        println()
         */
    }
}


fun main() {
    input_data()
    solution()
    if (escapable) {
        println("Yes")
        return
    }
    println("No")
    return
}