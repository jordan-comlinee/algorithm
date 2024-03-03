import java.util.Scanner
fun main() {
    val scanner = Scanner(System.`in`)
    var n = scanner.nextInt()
    while (n != 1) {
        for (i in 2..n) {
            if (n % i == 0) {
                n /= i
                println(i)
                break
            }
        }
    }
}
