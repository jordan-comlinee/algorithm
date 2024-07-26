import java.util.*
import java.io.*
import kotlin.math.*
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (K, N)  = br.readLine().split(" ").map{ it.toInt() }
    val cable = LongArray(N)
    repeat(K) {k ->
        cable[k] = br.readLine().toLong()
    }
    var end : Long = cable.max() + 1
    var start : Long = 1
    while ( start+1 < end ) {
        var n : Long = 0
        val mid = (end + start)/2
        repeat(K) { k->
            n += (cable[k]) / mid

        }
        if (n >= N) {
            start = mid
        }
        else {
            end = mid
        }
    }
    println(start)

}