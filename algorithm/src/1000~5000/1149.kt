package `1000~5000`// Dynamic Programming

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.min

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    var rgb_list = Array(N) {IntArray(3)}
    for (n in 0 until N) {
        val st = StringTokenizer(br.readLine())
        for (i in 0 until 3) {
            rgb_list[n][i]= st.nextToken().toInt()
        }
    }
    for (i in 1 until N) {
        rgb_list[i][0] += min(rgb_list[i-1][1], rgb_list[i-1][2])
        rgb_list[i][1] += min(rgb_list[i-1][0], rgb_list[i-1][2])
        rgb_list[i][2] += min(rgb_list[i-1][0], rgb_list[i-1][1])
    }
    println(rgb_list[N-1].min())


}