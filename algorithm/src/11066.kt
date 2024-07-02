import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main() {
    val br = System.`in`.bufferedReader()
    val t = br.readLine().toInt()
    val sb = StringBuilder()
    repeat(t) {
        val n = br.readLine().toInt()
        val files = br.readLine().split(" ").map { it.toInt() }
        sb.append(mergeFiles(n,files)).append("\n")
    }
    println(sb.toString())
}

fun mergeFiles(n : Int, files : List<Int>) : Int {
    val sum = IntArray(n + 1) { 0 }
    val dp = Array(n) { IntArray(n) { 0 } }

    // 빠른 부분합을 위한 누적합 배열
    for (i in 1..n) {
        sum[i] = sum[i - 1] + files[i - 1]
    }

    // d 길이 그룹
    for (d in 1 until n) {
        // i 번째 부터 시작
        for (i in 0 until n - d) {
            // j 까지
            val j = i + d
            dp[i][j] = Int.MAX_VALUE
            // m은 i와 j사이에 파일을 나누는 위치
            // i에서 j 까지 최소 비용 = [각 m 위치에서 나누었을 때 가장 최소 비용 + i에서 j까지 누적합]
            for (m in i until j) {
                dp[i][j] = dp[i][j].coerceAtMost(dp[i][m] + dp[m + 1][j] + sum[j + 1] - sum[i])
            }
        }
    }

    return dp[0][n - 1]
}
