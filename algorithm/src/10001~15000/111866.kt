package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (N, K) = br.readLine().split(" ").map { it.toInt() }
    val circle = ArrayList<Int>()
    val josephus = ArrayList<Int>()
    var next = 0
    repeat(N) { n ->
        circle.add(n+1)
    }
    while (circle.isNotEmpty()) {
        next += K - 1
        while (next > circle.lastIndex) next -= circle.size
        josephus.add(circle.removeAt(next))
    }
    println("<${josephus.joinToString(", ")}>")

}