package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    val N = st.nextToken().toInt()
    val M = st.nextToken().toInt()
    val st2 = StringTokenizer(br.readLine())
    val wood = Array(N) {st2.nextToken().toInt()}
    var start = 0
    var end = wood.max()
    while (start+1 < end) {
        // 답의 범위 때문에 Long 형으로 처리해야 함
        var result = 0L
        val H = (start+end)/2
        for (i in wood) {
            if (i >= H) {
                result += i - H
            }
        }
        if (result.toInt() == M) {
            println(H)
            return
        }
        if (result > M) start = H
        else end = H
    }
    println(start)
}