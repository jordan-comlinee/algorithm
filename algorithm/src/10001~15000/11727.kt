package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    var dp = IntArray(N+2){1}
    dp[2] = 3
    if (N >= 3) {
        for(i in 3 .. N) {
            dp[i] = (dp[i-2]*2 + dp[i-1]) % 10007
        }
    }
    println("${dp[N]}")
}