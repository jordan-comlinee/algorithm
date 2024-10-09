package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (A, B, C) = br.readLine().split(" ").map { it.toLong() }
    println(division(A, B, C))
}

private fun division(A: Long, B: Long, C: Long): Long {
    return when(B) {
        0L -> 1
        1L -> A % C
        else -> {
            val n = division(A, B / 2, C)

            if(B % 2 == 0L) (n * n) % C
            else ((n * n) % C) * A % C
        }
    }
}