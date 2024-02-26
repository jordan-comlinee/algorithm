import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    for (i in 0 until nextInt()) {
        var time = nextInt()
        var str =  next()
        for (n in 0 until str.length)  {
            for (m in 0 until time) {
                print("${str[n]}")
            }
        }
        println("")

    }
}