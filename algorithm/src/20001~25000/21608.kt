package `20001~25000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.pow

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    val students = Array(N*N){IntArray(5)}
    val board = Array(N){ IntArray(N) }
    var result = 0
    repeat(N*N) { i ->
        val st = StringTokenizer(br.readLine())
        repeat(5) { j ->
            students[i][j] = st.nextToken().toInt()
        }
    }
    for (i in 0 until N*N) {
        arrange(board, students[i], N)
    }

}

private fun arrange(board: Array<IntArray>, students: IntArray, N : Int) {

}