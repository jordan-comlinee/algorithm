package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val triangle = Array(n) {IntArray(n) }
    repeat(n) {
        triangle[it] = br.readLine().split(" ").map { it.toInt() }.toIntArray()
    }
    for (i in 1 until n) {
        for (j in 0..i) {
            when(j) {
                0 -> {
                    triangle[i][j] += triangle[i-1][0]
                }
                i -> {
                    triangle[i][j] += triangle[i-1][j-1]
                }
                else -> {
                    triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1])
                }
            }
        }
    }

    println(triangle[n-1].max())
}