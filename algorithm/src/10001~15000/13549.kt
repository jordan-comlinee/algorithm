package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.StringTokenizer


private var N = 0
private var K = 0
private var cnt = Int.MAX_VALUE
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    K = st.nextToken().toInt()
    bfs()
    println(cnt)
}

private fun bfs() {
    val queue: LinkedList<Pair<Int , Int>> = LinkedList()
    val visited = BooleanArray(100001)

    queue.offer(Pair(N, 0))
    visited[N] = true

    while (queue.isNotEmpty()) {
        val (current, count) = queue.poll()

        if (current == K) {
            cnt = count
            return
        }
        if (current*2 <= 100000 && !visited[current*2]) {
            queue.offerFirst(Pair(current*2, count))
            visited[current*2] = true
        }
        if (current-1 >= 0 && !visited[current-1]) {
            queue.offerLast(Pair(current-1, count+1))
            visited[current-1] = true
        }
        if (current+1 <= 100000 && !visited[current+1]) {
            queue.offerLast(Pair(current+1, count+1))
            visited[current+1] = true
        }

    }
}