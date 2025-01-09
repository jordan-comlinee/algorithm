// 손님이 먹을 수 있는 초밥 가짓수의 최댓값을 구하는 프로그램
// N개의 초밥 레일
// 초밥의 가짓수
// k개 연속으로 먹기
// 무료 초밥 번호, 없을 경우 요리사가 제공함
// 완전 탐색 수행, 초밥 래일이 회전 하므로
// [0:k-1]까지의 초밥을 이어 붙여 '회전 초밥'(LinkedList)을 구현한다.
package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    var result = 0
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (N, d, k, c) = br.readLine().split(" ").map { it.toInt() }
    val sushi = mutableListOf<Int>()
    repeat(N) {
        sushi.add(br.readLine().toInt())
    }
    for (i in 0 until k-1) {
        sushi.add(sushi[i])
    }
    // 완전 탐색 수행
    for (i in 0 until N) {
        val sushi_set = sushi.slice(i until i+k).toMutableSet()
        sushi_set.add(c)
        result = max(result, sushi_set.count())
        if (sushi_set.count()  == k + 1) {
            break
        }

    }
    println(result)
}