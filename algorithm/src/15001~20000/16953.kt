package `15001~20000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (A, B) = br.readLine().split(" ").map { it.toLong() }
    var cnt = bfs(A, B)
    println(cnt)
}

private fun bfs(A: Long, B: Long) : Long {
    val queue = LinkedList<Pair<Long, Long>>()
    queue.add(Pair(A, 1L))
    while (queue.isNotEmpty()) {
        val current = queue.poll()
        if (current.first == B) {
            return current.second
        }
        if (current.first*2 <= B) {
            queue.offer(Pair(current.first * 2, current.second + 1))
        }
        if (current.first*10+1 <= B) {
            queue.offer(Pair(current.first * 10 + 1, current.second + 1))
        }
    }
    return -1
}