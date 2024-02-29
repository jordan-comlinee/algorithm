import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    var result = 0
    for (i in 0 until n) {
        var m = nextInt()
        var t = 1
        if (m == 1) t = 0
        for (j in 2 until m) {
            if (m%j == 0) t = 0
        }
        result += t
    }
    println("${result}")
}