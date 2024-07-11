package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = Array(5) {0}
    var hap = 0
    repeat(5) {
        n[it] = br.readLine().toInt()
        hap += n[it]
    }
    n.sort()
    println("${hap/5}\n${n[2]}")
}