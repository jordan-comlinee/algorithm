package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.min

private var N = 0
private var total = 0
private var sum = 0
private lateinit var county : IntArray
private lateinit var br : BufferedReader
private lateinit var st : StringTokenizer

private fun input_data(){
    br = BufferedReader(InputStreamReader(System.`in`))
    N = br.readLine().toInt()
    county = IntArray(N)
    county = br.readLine().split(" ").map { it.toInt() }.toIntArray()
    sum = county.sum()
    county.sort()
    total = br.readLine().toInt()
}

fun getSum(m : Int) : Int{
    var sum = 0;
    county.forEach {
        sum += min(m, it)
    }
    return sum
}

fun solution() : Int{
    var result = 0
    if (sum < total)
        return county[N-1]
    var s = 0
    var b = county[N-1]
    while (s <= b) {
        var m = (s+b)/2
        if(getSum(m) <= total) {
            result = m
            s = m+1
        }
        else {
            b = m-1
        }
    }
    return result
}

fun main() {
    input_data()
    val result = solution()
    println(result)
}