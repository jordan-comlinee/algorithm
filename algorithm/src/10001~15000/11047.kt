package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    val N = st.nextToken().toInt()
    var K = st.nextToken().toInt()
    val coin = Array(N) {0}
    for (i in 0 until N) {
        coin[i] = br.readLine().toInt()
    }
    var result = 0
    for (i in N-1 downTo 0) {
        if (K == 0) break
        if (K/coin[i] >= 1) {
            result += K/coin[i]
            K = K % coin[i]
        }
    }
    println("${result}")
}