import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

private lateinit var arr : Array<Int>
private lateinit var visited : Array<Boolean>
private var N = 0
private var M = 0

private val br = BufferedReader(InputStreamReader(System.`in`))
private val st = StringTokenizer(br.readLine())
private val bw = BufferedWriter(OutputStreamWriter(System.out))


fun main() {
    N = st.nextToken().toInt()
    M = st.nextToken().toInt()
    arr = Array(N){0}
    visited = Array(N){false}
    val st2 = StringTokenizer(br.readLine())
    for (i in 0 until N) {
        arr[i] = st2.nextToken().toInt()
    }
    arr.sort()
    dfs(0, 0, "")
    bw.flush()
    bw.close()
    br.close()

}

private fun dfs(idx: Int, len: Int, st: String) {
    if (len == M) {
        bw.write(st.trim()+"\n")
        return
    }

    var temp = 0

    for (i in 0 until N) {
        if (!visited[i] && temp != arr[i]) {
            visited[i] = true
            temp = arr[i]
            dfs(i, len+1, "$st${arr[i]} ")
            visited[i] = false
        }
    }
}