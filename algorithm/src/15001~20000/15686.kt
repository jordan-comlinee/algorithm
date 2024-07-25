package `15001~20000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import java.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (N, M) = br.readLine().split(" ").map { it.toInt() }
    val city = Array(N) { Array(N) {0} }
    val chicken = mutableListOf<Array<Int>>()
    val home = mutableListOf<Array<Int>>()
    repeat(N) { i ->
        val st = StringTokenizer(br.readLine())
        repeat(N) { j ->
            city[i][j] = st.nextToken().toInt()
            if (city[i][j] == 2) chicken.add(arrayOf(i, j))
            if (city[i][j] == 1) home.add(arrayOf(i, j))
        }
    }

}