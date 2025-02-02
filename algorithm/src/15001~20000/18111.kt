package `15001~20000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import java.util.TreeMap
import kotlin.math.*

private lateinit var home : Array<IntArray>
private var max = 0
private var min = 256

private fun getMaxMin() {
    for (heights in home) {
        max = max(heights.max(), max)
        min = min(heights.min(), min)
    }
}

private fun solution(N: Int, M: Int, B : Int) {
    var results = mutableListOf<Pair<Int, Int>>()
    for (height in min..max) {
        var time = 0
        var blocks = 0
        repeat(N) { x ->
            repeat(M) { y ->
                if (home[x][y] < height) { // 높이가 목표 높이보다 더 낮을 때 -> 블록 추가
                    time += (height - home[x][y])
                    blocks -= (height - home[x][y])
                }
                else if (home[x][y] > height) { // 높이가 블록 높이보다 더 높을 때 -> 블록 제거
                    time += (home[x][y] - height)*2
                    blocks += (home[x][y] - height)
                }
            }
        }
        if (blocks + B >= 0) {
            results.add(Pair(time, height))
        }
    }
    results.sortWith(compareBy({it.first}, { -it.second}))
    println("${results[0].first} ${results[0].second}")
}
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (N, M, B) = br.readLine().split(" ").map { it.toInt() }
    home = Array(N) {IntArray(M)}
    repeat(N) { x ->
        val st = StringTokenizer(br.readLine())
        repeat(M) { y ->
            home[x][y] = st.nextToken().toInt()
        }
    }
    getMaxMin()
    solution(N, M, B)
}