package softeer

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
private val MAX = 1000000007
private var K = 0L
private var P = 0L
private var N = 0L


fun pow(n : Long) : Long {
    if (n == 1L) return P
    var result = pow(n/2)
    result = (result*result) % MAX
    if (n%2 == 1L) result = (result * P) % MAX
    return result
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    K = st.nextToken().toLong()
    P = st.nextToken().toLong()
    N = st.nextToken().toLong()
    println("${(pow(N*10)*K)%MAX}")

}

/* 완전 탐색으로는 이 문제를 풀면 안된다. N*10이고, 이 횟수만큼 거듭제곱 시 시간이 너무 많이 걸릴 수 있다.
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    K = st.nextToken().toLong()
    P = st.nextToken().toLong()
    N = st.nextToken().toInt()
    repeat(N*10) {
        K = (K*(P%MAX)%MAX)
    }
    println("$K")
}
*/