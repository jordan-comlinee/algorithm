package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    val N = st.nextToken().toInt()
    val M = st.nextToken().toInt()
    val V = st.nextToken().toInt()
    val graph = Array(N+1) { IntArray(N+1) {0} }
    var visited = ArrayList<Int>()

    repeat(M) {
        val (x, y) = br.readLine().split(" ").map { it.toInt() }
        graph[x][y] = 1
        graph[y][x] = 1
    }
    dfs(V, graph, visited)
    println()

    visited = ArrayList<Int>()
    bfs(V, graph, visited)

}
fun dfs(start : Int, graph : Array<IntArray>, visit : ArrayList<Int>) {
    visit.add(start)
    print("$start ")
    for (i in 1 until graph.size) {
        if (graph[start][i] == 1 && !visit.contains(i)) {
            dfs(i, graph, visit)
        }
    }
}

fun bfs(start : Int, graph : Array<IntArray>, visit: ArrayList<Int>) {
    val queue = LinkedList<Int>()
    queue.add(start)
    visit.add(start)

    while (queue.isNotEmpty()) {
        val x = queue.poll()
        print("$x ")

        for (i in 1 until graph.size) {
            if (graph[x][i] == 1 && !visit.contains(i)) {
                queue.add(i)
                visit.add(i)
            }
        }

    }
}