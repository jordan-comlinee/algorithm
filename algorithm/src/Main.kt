import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

private var N : Int = 0
private var M : Int = 0
private lateinit var visited : BooleanArray
private lateinit var elements : IntArray
private val br = BufferedReader(InputStreamReader(System.`in`))
private val bw = BufferedWriter(OutputStreamWriter(System.out))
fun main() {
    val st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    M = st.nextToken().toInt()
    visited = BooleanArray(N+1)
    elements = IntArray(N+1) { i -> i }
    permutation(1, 0, "")
    bw.flush()
    bw.close()
    br.close()

}

fun permutation(idx : Int, len : Int, result : String) {
    if (len == M) {
        bw.write(result.trim() + "\n")
        return
    }
    for (i in idx .. N ) {
        if (!visited[i]) {
            visited[i] = true
            permutation(i, len+1, "$result ${elements[i]}")
        }
        visited[i] = false

    }

}