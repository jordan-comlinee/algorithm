import java.io.BufferedReader
import kotlin.math.sqrt

fun main() = with(System.`in`.bufferedReader()) {
    val input = readLine().split(" ").map { it.toInt() }
    getPrime(input[0], input[1])
}
private fun getPrime(m : Int, n: Int){
    var isPrime = BooleanArray(n+1) {true}
    // 제곱근까지만 판별
    val sqrt = sqrt(n.toDouble()).toInt()
    isPrime[1] = false
    // 아리토스테네스의 체 원리
    for (i in 2..sqrt) {
        if (!isPrime[i]) continue
        else {
            var j = 2
            while (i*j <= n) {
                if (isPrime[i*j]) isPrime[i*j] = false
                j++
            }
        }
    }

    for (i in m..n) {
        if (isPrime[i]) println(i)
    }
}