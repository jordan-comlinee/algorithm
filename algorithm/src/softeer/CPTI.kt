package softeer

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.experimental.*

private fun test() {
    var a = "1100".toByteArray()
    var b = "0110".toByteArray()
    for (i in 0 until 4) {
        println("${a[i]} ${b[i]} ${a[i].xor(b[i])}")
    }
}

private var N = 0
private var M = 0
private lateinit var br : BufferedReader
private lateinit var st : StringTokenizer
private lateinit var people : Array<ByteArray>
private var result = 0

fun main() {
    br = BufferedReader(InputStreamReader(System.`in`))
    st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    M = st.nextToken().toInt()
    result = 0
    people = Array<ByteArray>(N){ByteArray(M)}
    for (i in 0 until N) {
        people[i] = br.readLine().toByteArray()
    }
    for (i in 0 until N-1) {
        for (j in i+1 until N) {
            for (t in 0 until M) {
                if (people[i][t].xor(people[j][t]).toInt() == 0) {
                    result += 1
                    break
                }
            }
        }
    }
    println(result)
}