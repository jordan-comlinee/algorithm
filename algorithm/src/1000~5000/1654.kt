package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (K, N) = br.readLine().split(" ").map { it.toInt() }
    val cable = LongArray(N)
    repeat(K) {
        cable[it] = br.readLine().toLong()
    }
    var end : Long = cable.max()+1
    var start : Long= 1
    while (start+1 < end) {
        var n : Long = 0
        val mid = (end+start)/2
        repeat(K) {
            n += (cable[it]) / mid
        }
        if (n >= N) {
            start = mid
        }
        else {
            end = mid
        }

    }
    println(start)
}