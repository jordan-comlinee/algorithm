package `1000~5000`
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

private var w = Int.MAX_VALUE
private var h = Int.MAX_VALUE
private var result = 0
private lateinit var st : StringTokenizer
private var dx = listOf(-1, -1, -1, 0, 0, 1, 1, 1)
private var dy = listOf(-1, 1,  0, 1, -1, -1, 0, 1)
private fun input_data() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    while (true) {
        st = StringTokenizer(br.readLine())
        w = st.nextToken().toInt()
        h = st.nextToken().toInt()
        if (w == 0 && h == 0) break
        var island_map = Array(h){IntArray(w){0} }
        repeat(h) { i ->
            island_map[i] = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        }
        val visited = Array(h) { BooleanArray(w) }
        solution(island_map, visited)
    }
}

private fun solution(island_map : Array<IntArray>, visited : Array<BooleanArray>) {
    for (i in 0 until h) {
        for (j in 0 until w) {
            if (!visited[i][j] && island_map[i][j] == 1) {
                dfs(island_map, visited, i, j)
                result+=1
            }
        }
    }
    println("$result")
    visited.fill(BooleanArray(w){false})
    result = 0
}

private fun dfs(island_map : Array<IntArray>, visited : Array<BooleanArray>, x : Int, y : Int) {
    for (i in 0 until dx.size) {
        val nx = x + dx[i]
        val ny = y + dy[i]
        if (nx in 0 until h && ny in 0 until w && !visited[nx][ny] && island_map[nx][ny] == 1) {
            visited[nx][ny] = true
            dfs(island_map, visited, nx, ny)
        }
    }
}
fun main() {
    input_data()
}