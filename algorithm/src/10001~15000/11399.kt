package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    val atm = br.readLine().split(" ").map { it.toInt() }
    val sorted_atm = atm.sortedDescending()
    var result = 0
    repeat(N) {
        result = result + sorted_atm[it] * (it + 1)
    }
    println(result)
}
