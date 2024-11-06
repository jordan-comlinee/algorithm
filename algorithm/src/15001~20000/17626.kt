import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    var dp = IntArray(n+1){0}
    dp[1] = 1
    for (i in 2 .. n) {
        var min = 4
        var j = 1
        while (j*j <= i) {
            min = min(min, dp[i-j*j])
            j += 1
        }
        dp[i] = min+1
    }
    println("${dp[n]}")
}