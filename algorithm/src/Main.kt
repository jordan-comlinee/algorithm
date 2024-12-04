import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

private var n = 0
private var nodes = mutableMapOf<Int, ArrayList<Pair<Int, Int>>>()

private var result = 0
private var farthestNode = 0
fun dfs(start : Int, length : Int, visited : BooleanArray) {
    visited[start] = true
    if (length > result) {
        result = length
        farthestNode = start
    }
    for (neighbor in nodes[start]?:ArrayList()) {
      var next = neighbor.first
      var weight = neighbor.second
      if (!visited[next]) {
          dfs(next, length+weight, visited)
      }
    }
}

fun main() {
    var br = BufferedReader(InputStreamReader(System.`in`))
    var visited = BooleanArray(10001){false}
    n = br.readLine().toInt()
    repeat(n-1) {
        val (start, end, length) = br.readLine().split(" ").map { it.toInt() }
        nodes.getOrPut(start) {ArrayList()}.add(Pair(end, length))
        nodes.getOrPut(end) {ArrayList()}.add(Pair(start, length))
    }

    dfs(1, 0, visited)
    visited.fill(false)
    dfs(farthestNode, 0, visited)
    println("$result")

}