import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val N = nextInt()
    val M = nextInt()
    val num = Array(N+1){ 0 }
    val prefixSum = Array(N+1) {0}
    for (i in 1..N) {
        num[i] = nextInt()
        prefixSum[i] = prefixSum[i-1] + num[i]
    }
    for (j in 0 until M) {
        val x = nextInt()
        val y = nextInt()
        var result = 0
        println("${prefixSum[y]-prefixSum[x-1]}")
    }
}