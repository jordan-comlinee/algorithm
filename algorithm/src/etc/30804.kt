package etc

import java.io.BufferedReader
import java.io.InputStreamReader

private var result = 0
private lateinit var fruits : List<Int>
private var count = HashMap<Int, Int>()

private var N = 0

private fun solution() {
    var left = 0
    var right = 0
    while(right < N) {
        count[fruits[right]] = count.getOrDefault(fruits[right], 0) + 1

        while (count.size > 2) {
            count[fruits[left]] = count[fruits[left]]!! - 1
            if (count[fruits[left]] == 0) {
                count.remove(fruits[left])
            }
            left++
        }
        result = maxOf(result, right-left+1)
        right++
    }
}
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    N = br.readLine().toInt()
    fruits = br.readLine().split(" ").map { it.toInt() }
    solution()
    println("$result")
}