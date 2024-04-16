import java.util.Scanner
import kotlin.math.max

fun main() = with(Scanner(System.`in`)) {
    val x = nextInt()
    val stair = IntArray(x+1){0}
    for (i in 1 until x+1) {
        stair[i] = nextInt()
    }
    val maxScore = IntArray(x+1){0}

    for (i in 1 until x+1) {
        when(i) {
            0 -> maxScore[i] = 0
            1 -> maxScore[i] = stair[1]
            2 -> maxScore[i] = stair[1] + stair[2]
            else -> {
                maxScore[i] = max(stair[i] + maxScore[i - 2], stair[i]+stair[i-1]+maxScore[i-3])
            }
        }
    }
    println(maxScore[x])
}