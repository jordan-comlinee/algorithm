package `1000~5000`

import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    var n = nextInt()
    var count = 0
    var m = 665
    while (true) {
        if (m.toString().contains("666")) {
            count += 1
            if (count == n) break
        }
        m += 1
    }
    println(m)
}