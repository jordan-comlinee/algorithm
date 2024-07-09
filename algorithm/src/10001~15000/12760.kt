import java.io.BufferedReader

fun main() = with(System.`in`.bufferedReader()) {
    val arr = readLine().split(" ").map { it.toInt() }
    val N = arr[0]
    val M = arr[1]
    val cards = Array(N+1) { List(M) {0} }
    val score = Array(N+1) {0}
    val card = Array(N+1) {0}
    for (i in 1.. N) {
        cards[i] = readLine().split(" ").map { it.toInt() }
    }
    //for ()
}