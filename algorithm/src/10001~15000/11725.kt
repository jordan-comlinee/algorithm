package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.ArrayList
import java.util.LinkedList

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    val connected = Array(N+1){ArrayList<Int>()}
    repeat(N-1) {
        val (a, b) = br.readLine().split(" ").map { it.toInt() }
        connected[a].add(b)
        connected[b].add(a)
    }
    bfs(N, connected)
}

private fun bfs(N : Int, list: Array<ArrayList<Int>>) {
    val start = 1
    val visit = BooleanArray(N+1) { false }
    visit[start] = true
    val queue = LinkedList<Int>()
    queue.add(start)
    val result = IntArray(N+1){0}

    while (queue.isNotEmpty()) {
        val current = queue.pop()
        for (i in list[current]) {
            if (visit[i]) continue
            visit[i] = true
            result[i] = current
            queue.add(i)
        }
    }

    for (i in 2..N) {
        println("${result[i]}")
    }

}