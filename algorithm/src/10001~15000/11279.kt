package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.Collections
import java.util.PriorityQueue

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    // 디폴트는 최소 힙...Collections.reverseOrder()로 최대 힙 구현
    var h = PriorityQueue<Int>(Collections.reverseOrder())
    repeat(N) {
        val x = br.readLine().toInt()
        if (x == 0) {
            if (h.isEmpty()) println(0)
            // 빼기
            else println(h.poll())
        }
        else {
            // 넣기
            h.offer(x)
        }
    }

}