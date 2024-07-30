package `10001~15000`
import java.io.BufferedReader
import java.io.InputStreamReader
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (N, M) = br.readLine().split(" ").map { it.toInt() }
    val nodes = Array(N + 1) { mutableListOf<Int>() }
    val visited = BooleanArray(N + 1) { false }
    var cnt = 0

    repeat(M) {
        val (u, v) = br.readLine().split(" ").map { it.toInt() }
        nodes[u].add(v)
        nodes[v].add(u)
    }

    fun dfs(n : Int) {
        visited[n] = true
        for (i in nodes[n]) {
            if (!visited[i])
                dfs(i)
        }
    }
    for (i in 1..N) {
        if (!visited[i]) {
            dfs(i)
            cnt++
        }
    }
    println(cnt)
}
