import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    while (hasNextLine()) {
        val value = nextLine()

        if (value.isNotBlank()) {
            println(value)
        }
    }
}