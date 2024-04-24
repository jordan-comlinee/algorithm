// 처음 시간복잡도는 O(2^n)
/*
fun fibonacci(n : Int) : Int {
    if (n == 0) {
        cnt0 += 1
        return 0
    } else if (n == 1) {
        cnt1 += 1
        return 1
    } else {
        return fibonacci(n-1) + fibonacci(n-2)
    }
}
*/

// 현재 시간복잡도는 O(n)

import java.util.Scanner
fun main() = with(Scanner(System.`in`)) {
    var n = nextInt()
    for (i in 1..n) {
        findFibonacci(nextInt())
    }
}
fun findFibonacci(n : Int) {
    val fib = Array(n+2) { IntArray(3) {0} }
    fib[0] = intArrayOf(1, 0, 0)
    fib[1] = intArrayOf(0, 1, 1)
    if (n < 2) {
        println("${fib[n][0]} ${fib[n][1]}")
        return
    }

    for (i in 2..n) {
        for (j in 0..2) {
            fib[i][j] = fib[i - 1][j] + fib[i - 2][j]
        }
    }
    println("${fib[n][0]} ${fib[n][1]}")
}
