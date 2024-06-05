// Dynamic Programming

import java.util.Scanner
import kotlin.math.pow

fun main() = with(Scanner(System.`in`)) {
    val T = nextInt()

    for (t in 0 until T) {
        val N = nextInt()
        var N_list = IntArray(N)
        for (n in 0 until N) {
            if (n<3) {
                val v = (2.0).pow(n).toInt()
                N_list[n] = v
            }
            else {
                N_list[n] = N_list[n - 1] + N_list[n - 2] + N_list[n - 3]
            }
        }
        println(N_list[N-1])
    }
}