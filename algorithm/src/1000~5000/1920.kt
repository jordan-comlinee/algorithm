package `1000~5000`

import java.util.Scanner

fun isin(A : Int, n_list : Array<Int>) : Int {
    var left = 0
    var right = n_list.size - 1
    while (left <= right) {
        val mid = (left + right) / 2
        when {
            A == n_list[mid] -> return 1
            A > n_list[mid] -> left = mid + 1
            else -> right = mid - 1
        }
    }
    return 0
}

fun main() = with(Scanner(System.`in`)) {
    val N = nextInt()
    var n_list = Array(N) {0}
    for (i in 0 until N) {
        n_list[i] = nextInt()
    }
    n_list.sort()
    val M = nextInt()
    for (i in 1..M) {
        val A = nextInt()
        println(isin(A, n_list))
    }

}