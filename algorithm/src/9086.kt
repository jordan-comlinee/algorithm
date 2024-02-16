import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    for (i in 1..nextInt()) {
        var string = next()
        println("${string[0]}${string[string.length-1]}")
    }
}