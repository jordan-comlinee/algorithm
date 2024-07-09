import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    var n = nextInt()
    var b = nextInt()
    var result = StringBuilder()
    while (n>0) {
        if (n%b < 10) {
            result.append((n%b + '0'.toInt()).toChar())
        } else {
            result.append((n%b - 10 + 'A'.toInt()).toChar())
        }
        n = n/b
    }
    println(result.reverse())
}