package `15001~20000`

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

private var N = 0
private var M = 0
private lateinit var visited : BooleanArray
private lateinit var n : IntArray

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    M = st.nextToken().toInt()
    n = IntArray(N+1) { i->i }
    visited = BooleanArray(N+1) {false}
    solution(1, 0, "", bw)
    bw.flush()
    bw.close()
    br.close()
}

fun solution(idx : Int, len : Int, str : String ,bw : BufferedWriter) {
    if (len == M) {
        bw.write(str)
        bw.write("\n")
    }

    for (i in idx..N) {
        if (!visited[i]) {
            visited[i] = true
            if (len == 0) {
                solution(i, 1, n[i].toString(), bw)
            }
            else {
                solution(i, len+1, "$str ${n[i]}", bw)
            }
            visited[i] = false
        }
    }

}
