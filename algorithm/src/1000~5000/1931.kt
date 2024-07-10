package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.nio.Buffer
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    val meeting = Array(N) {Array(2) {0} }
    for (i in 0 until N) {
        val st = StringTokenizer(br.readLine())
        meeting[i][0] = st.nextToken().toInt()
        meeting[i][1] = st.nextToken().toInt()
    }
    meeting.sortWith(compareBy<Array<Int>> {it[1]}.thenBy { it[0] })
    var cnt = 0
    var time = meeting[0][1]
    for (i in 1 until N) {
        if (time <= meeting[i][0]) {
            time = meeting[i][1]
            cnt++
        }
    }
    println(cnt+1)
}