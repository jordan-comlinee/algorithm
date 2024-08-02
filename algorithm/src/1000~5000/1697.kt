package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.Queue
import java.util.StringTokenizer

private var N = 0
private var K = 0
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    K = st.nextToken().toInt()
    val result = bfs(N, K)
    println(result)

}

fun bfs(n: Int, k: Int): Int {
    val queue: Queue<Pair<Int, Int>> = LinkedList() // n, depth
    val visited = mutableSetOf<Int>()
    queue.add(Pair(n, 0))
    visited.add(n)

    while (queue.isNotEmpty()) {
        val (current, depth) = queue.poll()

        if (current == k) {
            return depth
        }

        val nextPositions = listOf(current * 2, current + 1, current - 1)
        for (next in nextPositions) {
            if (next >= 0 && next !in visited) {
                queue.add(Pair(next, depth + 1))
                visited.add(next)
            }
        }
    }
    return -1
}