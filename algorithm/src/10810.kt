import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val N = nextInt()
    val M = nextInt()
    var buckets = IntArray(N)

    for (time in 0 until M) {
        val i = nextInt()
        val j = nextInt()
        val k = nextInt()

        for (num in i - 1 until j) {
            buckets[num] = k
        }
    }

    buckets.forEach { print("${it} ") }
}