package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var s = br.readLine().split("-").map { it }
    var result = s[0].split("+").sumOf { it.toInt() }
    for (i in 1 until s.size) {
        result -= s[i].split("+").sumOf { it.toInt() }
    }
    println(result)
}