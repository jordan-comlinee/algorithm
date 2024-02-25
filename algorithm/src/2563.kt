import java.util.Scanner
import kotlin.math.max

fun main() = with(Scanner(System.`in`)) {
    var t = nextInt()
    var max = 0
    var result = 0
    var paper = Array(t) { IntArray(2) }
    for (i in 0 until t){
        paper[i][0] = nextInt()
        paper[i][1] = nextInt()
        if (max < max(paper[i][0], paper[i][1])) max = max(paper[i][0], paper[i][1])
    }
    var dohwaji = Array(max+10) {IntArray(max+10) { 0 } }
    for (i in 0 until t) {
        var x = paper[i][0]
        var y = paper[i][1]
        for (n in 0 until 10) {
            for (m in 0 until 10) {
                if (dohwaji[x+n][y+m] == 0) {
                    dohwaji[x+n][y+m] = 1
                    result += 1
                }
            }
        }
    }
    println("${result}")
}