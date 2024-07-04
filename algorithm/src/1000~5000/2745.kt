package `1000~5000`

import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    var n = next()
    var m = nextInt()
    var result = 0
    for (i in 0 until n.length) {
        if ('0' <= n[i] && '9' >=n[i]) {
            result = result * m + (n[i] - '0')
        } else {
            result = result * m + (n[i] - 'A' + 10)
        }
    }

    print(result)
}