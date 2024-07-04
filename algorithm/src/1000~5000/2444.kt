package `1000~5000`

import java.util.*;
fun main(args: Array<String>) {
    val s = Scanner(System.`in`)
    var n = s.nextInt()
    for (i in 1..n) {
        for (j in 0 until n - i) print(" ");
        for (j in 0 until (i - 1) * 2 + 1) print("*")
        println()
    }
    for (i in n - 1 downTo 1) {
        for (j in 0 until n - i) print(" ");
        for (j in 0 until (i - 1) * 2 + 1) print("*")
        println()
    }
}