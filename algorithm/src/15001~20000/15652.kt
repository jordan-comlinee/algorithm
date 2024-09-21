import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

private var N = 0
private var M = 0
private lateinit var n : IntArray
private lateinit var visited : BooleanArray
private val br = BufferedReader(InputStreamReader(System.`in`))
private val bw = BufferedWriter(OutputStreamWriter(System.out))
fun main() {
    val st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    M = st.nextToken().toInt()
    visited = BooleanArray(N+1)
    n = IntArray(N+1) {i->i}
    var str = ""
    solution(1, 0, str)
    bw.flush()
    bw.close()
    br.close()
}

private fun solution(idx : Int, len : Int, result : String) {
    if (len == M) {
        bw.write(result.trim() + "\n")
        return
    }
    for (i in idx .. N) {
        solution(i, len + 1, "$result ${n[i]}")
    }
}