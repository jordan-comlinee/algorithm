package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    var A = List<Int>(N){0}
    A = br.readLine().split(" ").map { it.toInt() }
    val dp = IntArray(N) {1}
    for (i in 1 until N) {
        for (j in 0 until i) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j]+1)
            }
        }
    }
    println(dp.max())
}