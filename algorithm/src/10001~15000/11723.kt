package `10001~15000`

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val M = br.readLine().toInt()
    var S = Array<Boolean>(21) {false}
    var result = BufferedWriter(OutputStreamWriter(System.out))
    repeat(M) {
        val st = StringTokenizer(br.readLine())
        val operland = st.nextToken()
        when(operland) {
            "add" -> {
                S[st.nextToken().toInt()] = true
            }
            "remove" -> {
                S[st.nextToken().toInt()] = false
            }
            "check" -> {
                if (S[st.nextToken().toInt()])
                    result.write("1\n")
                else
                    result.write("0\n")
            }
            "toggle" -> {
                val x = st.nextToken().toInt()
                S[x] = !S[x]
            }
            "all" -> {
                S = Array(21) {true}
            }
            "empty" -> {
                S = Array(21) {false}
            }
        }
    }
    result.flush()
    result.close()
    br.close()
}