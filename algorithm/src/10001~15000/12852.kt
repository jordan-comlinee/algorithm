package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val X = br.readLine().toInt()

    val n = Array(X + 1) { 0 }  // 연산 횟수를 저장하는 배열
    val path = Array(X + 1) { 0 }  // 경로를 저장하는 배열

    for (i in 2..X) {
        n[i] = n[i - 1] + 1
        path[i] = i - 1
        if (i % 2 == 0 && n[i] > n[i / 2] + 1) {
            n[i] = n[i / 2] + 1
            path[i] = i / 2
        }
        if (i % 3 == 0 && n[i] > n[i / 3] + 1) {
            n[i] = n[i / 3] + 1
            path[i] = i / 3
        }
    }
    println(n[X])
    var current = X
    val resultPath = mutableListOf<Int>()
    while (current > 0) {
        resultPath.add(current)
        current = path[current]
    }
    println(resultPath.joinToString(" "))
}
