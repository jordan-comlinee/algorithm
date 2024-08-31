package `15001~20000`
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

private var N : Int = 0
private var M : Int = 0
private lateinit var visited : BooleanArray
private lateinit var elements : List<Int>
private val br = BufferedReader(InputStreamReader(System.`in`))
private val bw = BufferedWriter(OutputStreamWriter(System.out))
fun main() {
    val st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    M = st.nextToken().toInt()
    visited = BooleanArray(N)
    elements = br.readLine().split(" ").map { it.toInt() }
    elements = elements.sorted()
    solution(0, 0, "")
    bw.flush()
    bw.close()
    br.close()

}

private fun solution(idx : Int, len : Int, result : String) {
    if (len == M) {
        bw.write(result.trim() + "\n")
        return
    }
    for (i in idx ..< N ) {
        if (!visited[i]) {
            visited[i] = true
            solution(idx, len+1, "$result ${elements[i]}")
            visited[i] = false
        }
    }
}