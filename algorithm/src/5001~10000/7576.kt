package `5001~10000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    val M = st.nextToken().toInt()
    val N = st.nextToken().toInt()
    val board = Array(N){Array(M) {0} }
    repeat(N) { x->
        val st2 = StringTokenizer(br.readLine())
        repeat(M) { y->
            board[x][y] = st2.nextToken().toInt()
        }
    }

}