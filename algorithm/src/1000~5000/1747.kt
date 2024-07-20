package `1000~5000`
import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.sqrt

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    var M = N

    while (true) {
        if (M.toString() == M.toString().reversed() && isPrime(M)) {
            println("$M")
            break
        }
        M++
    }
}

private fun isPrime(N : Int) : Boolean {
    var prime = BooleanArray(N+1) {true}
    val sqrt = sqrt(N.toDouble()).toInt()
    prime[1] = false
    for (i in 2..sqrt) {
        if (!prime[i]) continue
        var j = 2
        while (i*j <= N) {
            if (prime[i*j]) prime[i*j] = false
            j++
        }
    }
    if (prime[N]) return true
    else return false
}