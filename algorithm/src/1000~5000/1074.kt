package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Math.pow
import kotlin.math.pow

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var (N, r, c) = br.readLine().split(" ").map { it.toInt() }
    var n = 2.0.pow(N).toInt()
    var result = 0
    var q = 0
    while (n>1) {
        when {
            r<n/2 && c<n/2 ->
                q = 0
            r<n/2 && c>=n/2 ->
                q = 1
            r>=n/2 && c<n/2 ->
                q = 2
            r>=n/2 && c>=n/2 ->
                q = 3
        }
        result = result + n.toDouble().pow(2).toInt()/4*q
        r %= n/2
        c %= n/2
        n /= 2
    }
    println(result)

}