import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val N = nextInt()
    val n = Array(N) {0}
    for (i in 0 until N) {
        n[i] = nextInt()
    }
    n.sort()
    for (i in 0 until N) {
        println(n[i])
    }
}