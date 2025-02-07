package softeer

import java.io.*
import java.util.*

private var N = 0
private lateinit var br: BufferedReader
private lateinit var phi: LongArray
private var q: Deque<Pair<Long, Int>> = ArrayDeque()
private var tmp_q: Deque<Pair<Long, Int>> = ArrayDeque()

private fun input_data() {
    br = BufferedReader(InputStreamReader(System.`in`))
    N = br.readLine().toInt()
    phi = br.readLine().split(" ").map { it.toLong() }.toLongArray()
}

private fun solution() {
    for (i in 0 until N) {
        q.offerLast(Pair(phi[i], i + 1))
    }

    while (q.size > 1) {
        while (q.isNotEmpty()) {
            var current = q.pollFirst()  // 맨 앞 원소를 가져옴
            var newValue = current.first
            // 왼쪽 값과 비교 (tmp_q의 마지막 값)
            val beforeValue = tmp_q.peekLast()
            val afterValue = q.peekFirst()
            if (beforeValue != null && beforeValue.first <= current.first) {
                tmp_q.pollLast()
                newValue += beforeValue.first
            }
            if (afterValue != null && afterValue.first <= current.first) {
                q.pollFirst()
                newValue += afterValue.first
            }
            tmp_q.offerLast(Pair(newValue, current.second))
        }
        q = LinkedList(tmp_q)
        tmp_q.clear()
    }
}

fun main() {
    input_data()
    solution()
    val result = q.peekFirst()
    println("${result.first}\n${result.second}")
}
