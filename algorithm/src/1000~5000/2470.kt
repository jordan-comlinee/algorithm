package `1000~5000`

import java.io.*
import java.util.*
import kotlin.math.*

private lateinit var br : BufferedReader
private var N = 0
private lateinit var liquid : IntArray
private var result = Triple(Int.MAX_VALUE, 0, 0)
private var left = 0
private var right = 0

private fun input_data() {
    br = BufferedReader(InputStreamReader(System.`in`))
    N = br.readLine().toInt()
    liquid = br.readLine().split(" ").map{ it.toInt() }.toIntArray()
    liquid.sort()
}

private fun solution() {
    left = 0
    right = N-1
    while (left < right) {
        var hap = liquid[left] + liquid[right]
        if(abs(hap) <= abs(result.first)) {
            //println("current value is smaller than prev : ${hap} ${result.first}")
            result = Triple(hap, left, right)
        }
        if(hap < 0) {
            left += 1
            //println("left : ${hap} ${left} ${right}")
        }
        else if (hap > 0) {
            right -= 1
            //println("right : ${hap} ${left} ${right}")
        }
        else {
            return
        }
    }
}

fun main() {
    input_data()
    solution()
    println("${liquid[result.second]} ${liquid[result.third]}")
}