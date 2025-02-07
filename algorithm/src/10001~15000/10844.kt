package `10001~15000`

import java.io.*
import java.util.*
import kotlin.math.*

private lateinit var br : BufferedReader
private var N = 0
private var result = 0
val max = 1000000000

private fun input_data() {
    br = BufferedReader(InputStreamReader(System.`in`))
    N = br.readLine().toInt()
}

private fun solution() : Int {
    var dp = Array<LongArray>(N+1){ LongArray(10){0} }
    for (i in 0 until 10) {
        dp[1][i] = 1;
    }
    for(i in 2 .. N) {
        dp[i][0] = dp[i-1][1]%max
        for (j in 1 until 9) {
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%max
        }
        dp[i][9] = dp[i-1][8]%max
    }
    return ((dp[N].sum()-dp[N][0])%max).toInt()
}

fun main(args: Array<String>) {
    input_data()
    result = solution()
    println("$result")
}