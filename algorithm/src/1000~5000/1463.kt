package `1000~5000`

import java.util.Scanner
import kotlin.math.min

fun main() = with(Scanner(System.`in`)) {
    var x = nextInt()
    var xp = mutableListOf(0, 0)
    for (i in 2..x) {
        xp.add(xp[i-1] + 1)
        if (i % 2 == 0) xp[i] = min(xp[i], xp[i/2] + 1)
        if (i % 3 == 0) xp[i] = min(xp[i], xp[i/3] + 1)
    }
    println(xp[x])
}