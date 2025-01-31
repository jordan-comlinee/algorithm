package softeer

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer



fun main() {
    var N = 0
    var car_list = mutableListOf<Int>()
    var result = 0
    val br = BufferedReader(InputStreamReader(System.`in`))
    N = br.readLine().toInt()
    car_list = br.readLine().split(" ").map{ it.toInt() }.toMutableList()
    result = (car_list.maxOrNull()?:0) + N - 1
    println("${result}")
}