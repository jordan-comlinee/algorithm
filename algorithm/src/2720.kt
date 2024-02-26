import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    var time = nextInt()
    for (i in 0 until time) {
        var money = nextInt()
        var change = IntArray(4) { 0 }
        change[0] = money/25
        money %=25
        change[1] = money/10
        money %= 10
        change[2] = money/5
        money %=5
        change[3] = money
        println("${change[0]} ${change[1]} ${change[2]} ${change[3]}")
    }
}