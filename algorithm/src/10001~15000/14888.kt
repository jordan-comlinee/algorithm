package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

private lateinit var st : StringTokenizer
private var N = 0
private lateinit var A : IntArray
private val opperands = IntArray(4){0}
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    N = br.readLine().toInt()
    A = br.readLine().split(' ').map { it.toInt() }.toIntArray()
    st = StringTokenizer(br.readLine())
    repeat(4) {
        opperands[it] = st.nextToken().toInt()
    }

}