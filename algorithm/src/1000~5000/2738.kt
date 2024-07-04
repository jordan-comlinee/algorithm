package `1000~5000`

import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val m = nextInt()
    val arr = Array(n) { IntArray(m) }
    for (i in 0..n-1) {
        for (j in 0..m-1) {
            arr[i][j] = nextInt()
        }
    }
    for (i in 0..n-1) {
        for (j in 0..m-1) {
            arr[i][j] += nextInt()
        }
    }
    for (i in 0..n-1) {
        for (j in 0..m-1) {
            print("${arr[i][j]} ")
        }
        println()
    }
}