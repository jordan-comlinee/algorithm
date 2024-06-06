// Dynamic Programming

import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val N = nextInt()
    var rgb_list = Array(N, {IntArray(3)})
    var reult_list = IntArray(N, {0})
    for (n in 0 until N) {
        for (i in 0 until 3) {
            rgb_list[n][i]= nextInt()
        }
    }
}