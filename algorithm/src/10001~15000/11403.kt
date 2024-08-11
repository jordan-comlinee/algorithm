package `10001~15000`

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.LinkedList
import java.util.StringTokenizer

private var N = 0
private lateinit var board : Array<IntArray>
private var queue = LinkedList<Int> ()
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    N = br.readLine().toInt()
    board = Array(N){IntArray(N)}
    repeat(N) { i ->
        val st = StringTokenizer(br.readLine())
        repeat(N) { j ->
            board[i][j] = st.nextToken().toInt()
        }
    }

    repeat(N) { i ->
        repeat(N) { j ->
            if (board[i][j] == 1)
                queue.add(j)
        }
        while (queue.isNotEmpty()) {
            val j = queue.poll()
            bfs(i, j)
        }
    }

    repeat(N) { i ->
        repeat(N) { j ->
            bw.write("${board[i][j]} ")
        }
        bw.write("\n")
    }
    bw.flush()
    bw.close()

}

private fun bfs(i : Int, j : Int){
    board[i][j] = 1
    for (k in 0 until N) {
        if (board[i][k] == 0 && board[j][k] == 1)
            queue.add(k)
    }
}