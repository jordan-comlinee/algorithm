package `5001~10000`

import java.io.BufferedReader
import java.io.InputStreamReader
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val T = br.readLine().toInt()
    repeat(T) {
        val n = br.readLine().toInt()
        val closet = HashMap<String, Int>()
        repeat(n) {
            val (a, b) = br.readLine().split(" ").map { it }
            if (closet.containsKey(b)) {
                closet[b] = closet[b]!!+1
            }
            else closet[b] = 1
        }
        var result = 1
        for (i in closet.values) result *= (i+1)
        println(result-1)
    }

}