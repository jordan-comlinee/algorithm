import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    val numbers = Array(N){ Array(3){0} }
    val minNumbers = Array(N){ Array(3){0} }
    repeat(N) { x ->
        val st = StringTokenizer(br.readLine())
        repeat(3) { y ->
            numbers[x][y] = st.nextToken().toInt()
            minNumbers[x][y] = numbers[x][y]
        }
    }

    for (i in 1 until N) {
        numbers[i][0] += max(numbers[i-1][0], numbers[i-1][1])
        numbers[i][1] += numbers[i-1].max()
        numbers[i][2] += max(numbers[i-1][1], numbers[i-1][2])
        minNumbers[i][0] += min(minNumbers[i-1][0], minNumbers[i-1][1])
        minNumbers[i][1] += minNumbers[i-1].min()
        minNumbers[i][2] += min(minNumbers[i-1][1], minNumbers[i-1][2])
    }

    println("${numbers[N-1].max()} ${minNumbers[N-1].min()}")


}
