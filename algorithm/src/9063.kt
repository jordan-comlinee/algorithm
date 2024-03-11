import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val marble = nextInt()
    var x_list = mutableListOf<Int>()
    var y_list = mutableListOf<Int>()

    for (i in 0 until marble) {
        x_list.add(nextInt())
        y_list.add(nextInt())
    }

    println("${(x_list.max()-x_list.min())*(y_list.max()-y_list.min())}")
}