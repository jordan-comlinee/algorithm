import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (N, M) = br.readLine().split(" ").map { it.toInt() }
    val numbers = Array(N+1){Array(N+1){0}}
    repeat(N) { x ->
        val st = StringTokenizer(br.readLine())
        repeat(N) { y ->
            numbers[x+1][y+1] = st.nextToken().toInt()+numbers[x][y+1]+numbers[x+1][y]-numbers[x][y]
        }
    }

    repeat(M) {
        val (x1, y1, x2, y2) = br.readLine().split(" ").map { it.toInt() }
        bw.write("${numbers[x2][y2] - numbers[x2][y1 - 1] - numbers[x1 - 1][y2] + numbers[x1 - 1][y1 - 1]}\n")
    }

    bw.flush()
    bw.close()
    br.close()

}