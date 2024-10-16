package `20001~25000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.pow

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    val students = Array(N.toDouble().pow(2).toInt()+1){IntArray(4)}
    repeat(N.toDouble().pow(2).toInt()) {
        val st = StringTokenizer(br.readLine())
        val a = st.nextToken().toInt()
        repeat(4) {
            students[a][it] = st.nextToken().toInt()
        }
    }
}