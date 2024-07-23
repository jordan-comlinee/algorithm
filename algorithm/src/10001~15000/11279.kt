package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.Collections
import java.util.PriorityQueue

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    var h = PriorityQueue<Int>(Collections.reverseOrder())
    repeat(N) {
        val x = br.readLine().toInt()
        if (x == 0) {
            if (h.isEmpty()) println(0)
            else println(h.poll())
        }
        else {
            h.offer(x)
        }
    }

}