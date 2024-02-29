import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    while (true) {
        val n = nextInt()
        val sb = StringBuilder()
        var sum = 0
        if ( n == -1 ) break
        for (i in 1 until n) {
            if (n%i == 0) {
                sb.append("$i + ")
                sum += i
            }
        }

        if (n == sum ) {
            println("${n} = ${sb.toString().substring(0, sb.length - 3)}")
        } else {
            println("$n is NOT perfect.")
        }

    }
}