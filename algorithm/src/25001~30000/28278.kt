import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val sb = StringBuilder()
    val N = br.readLine().toInt()
    val stack = Array(1000000) {0}
    var top = -1
    repeat(N) {
        val st = StringTokenizer(br.readLine())
        when (st.nextToken().toInt()){
            1 -> {
                stack[++top] = st.nextToken().toInt()
            }
            2 -> {
                if (top == -1) sb.append("-1\n")
                else {
                    sb.append("${stack[top--]}\n")
                }
            }
            3 -> {
                sb.append("${top+1}\n")
            }
            4 -> {
                if (top == -1) sb.append("1\n")
                else sb.append("0\n")
            }
            5 -> {
                if (top == -1) sb.append("-1\n")
                else sb.append("${stack[top]}\n")
            }
        }
    }
    println(sb.toString())
}